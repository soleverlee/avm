#ifndef _AVM_JAVA_VM_H_
#define _AVM_JAVA_VM_H_

#include <string>

#include "class_loader.h"
#include "classpath_class_loader.h"
#include "runtime/method_area.h"
#include "runtime/vm_thread.h"

namespace avm {

class VirtualMachine {
public:
    VirtualMachine(const std::string &classpath, const std::string &mainClass);
    virtual ~VirtualMachine();
public:
    void execute();
    void execute(VmThread* thread);
protected:
    VmClass* getClass(const std::string &className) const;
protected:
    std::string _classPath;
    std::string _mainClass;
    ClassLoader *_classLoader;
    MethodArea *_methodArea;
    VmThread *_mainThread;
};
}

#endif
