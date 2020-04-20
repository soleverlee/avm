#ifndef _AVM_VM_THREAD_H_
#define _AVM_VM_THREAD_H_

#include "vm_stack.h"
#include "vm_class.h"
#include "vm_method.h"
#include "vm/interpreter.h"

namespace avm {
class VirtualMachine;
class VmThread {
public:
    VmThread(const VmClass* entryClass, const VmMethod* entryMethod, VirtualMachine* jvm);
    virtual ~VmThread();
public:
    void execute();
    Frame* currentFrame();
    const Instruction* nextInstruction();
    const VmClass* currentClass();
    const VmMethod* currentMethod();
protected:
    int _pcRegister;
    VmStack _vmStack;
    const VmClass* _entryClass;
    const VmMethod* _entryMethod;
    VirtualMachine* _jvm;
};
}
#endif
