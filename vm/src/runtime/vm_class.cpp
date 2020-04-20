#include "vm/runtime/vm_class.h"

#include <iostream>

using namespace avm;

VmClass::VmClass(std::shared_ptr<JavaClass> javaClass)
    : _javaClass(javaClass),
      _superClass(nullptr),
      _fieldSlots(0),
      _prepared(false) {
}

VmClass::~VmClass() {

}

const ConstantPool* VmClass::getRuntimeConstantPool() const {
    return _javaClass->getConstantPool();
}

const VmMethod VmClass::getClassInitializationMethod() const {
    try {
        const MethodInfo* cinit = _javaClass->getMethod("<cinit>", "()V");
        return VmMethod(cinit);
    } catch(MethodNotFoundException) {
        return nullptr;
    }
}

void VmClass::initialize() {
    // todo: <cinit>
}

void VmClass::prepare() {
    if(_prepared)
        return;
    int slotId = 0;
    if(_superClass) {
        slotId = _superClass->_fieldSlots;
    }
    int fieldsCount = _javaClass->getFieldsCount();
    for(int i = 0; i < fieldsCount; i++) {
        const FieldInfo* fieldInfo = _javaClass->getFieldAt(i);
        std::unique_ptr<VmField> field;

        if(fieldInfo->isStatic()) {
            /*
             * https://docs.oracle.com/javase/specs/jvms/se7/html/jvms-4.html#jvms-4.7.2
            */
            field = VmField::newStaticField(fieldInfo->getName(), fieldInfo->getDescriptor());
            const ConstantValue* constantValue = (ConstantValue*)fieldInfo->getAttrinuteIfPresent(CONSTANT_VALUE);
            if(constantValue != nullptr) {
                u2 index = constantValue->getValueIndex();
                initializeConstantField(*field, index);
            }
        } else {
            // instance fields are located in heap
            field = VmField::newInstanceField(fieldInfo->getName(), fieldInfo->getDescriptor(), slotId);
            slotId += field->getFieldSlotsSize();
        }
        _fields[fieldInfo->getName()] = std::move(field);
    }
    _fieldSlots = slotId;
    _prepared = true;
}

/*
    Field Type 	Entry Type
    long 	                             CONSTANT_Long
    float 	                             CONSTANT_Float
    double 	                             CONSTANT_Double
    int, short, char, byte, boolean 	 CONSTANT_Integer
    String 	                             CONSTANT_String
*/
void VmClass::initializeConstantField(VmField& field, u2 constantIndex) {
    const ConstantInfo* info = _javaClass->getConstantPool()->at(constantIndex);
    switch(field.getDescriptor().getBaseType()) {
    case FIELD_Byte:
    case FIELD_Short:
    case FIELD_Char:
    case FIELD_Int:
    case FIELD_Boolean: {
        ConstantInteger* c = (ConstantInteger*) info;
        field.setInt(c->getValue());
        break;
    }
    case FIELD_Float: {
        ConstantFloat* c = (ConstantFloat*) info;
        field.setFloat(c->getValue());
        break;
    }
    case FIELD_Long: {
        ConstantLong* c = (ConstantLong*) info;
        field.setLong(c->getValue());
        break;
    }
    case FIELD_Double: {
        ConstantDouble* c = (ConstantDouble*) info;
        field.setDouble(c->getValue());
        break;
    }
    case FIELD_Reference: {
        ConstantString* c = (ConstantString*) info;
        const std::string* stringRef =  _javaClass->getConstantPool()->getStringReference(c->getStringIndex());
        field.setReference(reinterpret_cast<int64_t>(stringRef));
        break;
    }
    default:
        break;
    }
}