#ifndef _AVM_VM_METHOD_H_
#define _AVM_VM_METHOD_H_

#include "class_file/format/method_info.h"
#include "class_file/format/descriptor_type.h"
#include <vector>

namespace avm {
class VmClass;

class VmMethod {
public:
    VmMethod(const MethodInfo* method, const VmClass* methodClass);
    virtual ~VmMethod();
public:
    inline std::string getName() const {
        return _name;
    }
    inline std::string getDescriptor() const {
        return _descriptor;
    }
    inline const VmClass* getClass() const {
        return _class;
    }
    inline bool isStatic() const {
        return _javaMethod->isStatic();
    }
    inline bool isNative() const {
        return _javaMethod->isNative();
    }
    u2 getMaxLocals() const;
    u2 getMaxStack() const;
    u2 getInstructionsCount() const;
    const Instruction* getInstruction(u2 index) const;
    u2 getParameterCount() const;
    FieldType getParameterAt(u2 index) const;
protected:
    const VmClass* _class;
    const std::string _name;
    const std::string _descriptor;
    const MethodInfo* _javaMethod;
    const bool _isNative;
    u2 _parameterCount;
    std::vector<FieldType> _parameters;
};
}

#endif