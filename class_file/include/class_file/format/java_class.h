#ifndef _AVM_JAVA_CLASS_H_
#define _AVM_JAVA_CLASS_H_

#include <vector>
#include <memory>
#include <initializer_list>

#include "types.h"
#include "constant_pool.h"
#include "access_flags.h"
#include "field_info.h"
#include "method_info.h"
#include "with_attributes.h"

namespace avm {
class JavaClassParser;

class JavaClass: public WithAttributes {
    friend class JavaClassParser;
public:
    JavaClass();
    virtual ~JavaClass();
public:
    inline u4 getMagic() const {
        return _magic;
    }
    inline u2 getMinorVersion() const {
        return _minorVersion;
    }
    inline u2 getMajorVersion() const {
        return _majorVersion;
    }
    inline const ConstantPool* getConstantPool() const {
        return _constantPool.get();
    }
    inline u2 getConstantPoolCount() const {
        return _constantPool->getConstantPoolCount();
    }
    const ConstantInfo* getConstantAt(const u2 index) const;
    inline u2 getAccessFlags() const {
        return _accessFlags;
    }
    inline u2 getThisClass() const {
        return _thisClass;
    }
    inline u2 getSuperClass() const {
        return _superClass;
    }
    inline bool hasSuperClass() const {
        return _superClass != 0;
    }
    inline u2 getInterfacesCount() const {
        return _interfacesCount;
    }
    u2 getInterfaceAt(const u2 index) const;
    inline u2 getFieldsCount() const {
        return _fieldsCount;
    }
    const FieldInfo* getFieldAt(const u2 index) const;
    inline u2 getMethodsCount() const {
        return _methodsCount;
    }
    const MethodInfo* getMethodAt(const u2 index) const;
public:
    inline bool isPublic() const {
        return _accessFlags & ACC_PUBLIC;
    }
    inline bool isFinal() const {
        return _accessFlags & ACC_FINAL;
    }
    inline bool isSuper() const {
        return _accessFlags & ACC_SUPER;
    }
    inline bool isInterface() const {
        return _accessFlags & ACC_INTERFACE;
    }
    inline bool isAbstract() const {
        return _accessFlags & ACC_ABSTRACT;
    }
    inline bool isSynthetic() const {
        return _accessFlags & ACC_SYNTHETIC;
    }
    inline bool isAnnotation() const {
        return _accessFlags & ACC_ANNOTATION;
    }
    inline bool isEnum() const {
        return _accessFlags & ACC_ENUM;
    }
public:
    const MethodInfo* getMethod(const std::string &name,
                                const std::string &descriptor) const;
    const MethodInfo* getMethod(const std::string &name,
                                const std::string &descriptor,
                                int flagsCount,
                                ...) const;
    std::string getClassName() const;
    std::string getSuperClassName() const;
    std::string getInterfaceName(const u2 index) const;
private:
    void clearInterfaces();
    void clearFields();
    void clearMethods();
    void initializeInterfaces();
    void initializeFields();
    void initializeMethods();
    void setConstantPoolReferences();
protected:
    /*
     * allow copy & move only for children
     * https://stackoverflow.com/questions/8777724/store-derived-class-objects-in-base-class-variables
     */
    JavaClass(JavaClass&&) {
    }
    JavaClass(const JavaClass&) {
    }
    JavaClass& operator=(const JavaClass&) {
    }
private:
    u4 _magic;
    u2 _minorVersion;
    u2 _majorVersion;
    std::unique_ptr<ConstantPool> _constantPool;
    u2 _accessFlags;
    u2 _thisClass;
    u2 _superClass;
    u2 _interfacesCount;
    u2 *_interfaces;
    u2 _fieldsCount;
    FieldInfo *_fields;
    u2 _methodsCount;
    MethodInfo *_methods;
};
}

#endif
