#include "vm/interpreter.h"
#include "vm/exceptions.h"
#include "vm/virtual_machine.h"
#include "vm/thread_context.h"
#include "gtest/gtest.h"

using namespace avm;

TEST(Interperter, getStatic) {
    VirtualMachine vm("res", "com/vm/HelloWorld");
    auto vmClass = vm.getClass("com/op/FieldOperations");
    
    int pc = 0;
    VmStack stack;
    auto frame = std::unique_ptr<Frame>(new Frame(3, 3, vmClass->getRuntimeConstantPool(), nullptr));
    stack.push(std::move(frame));

    Context ctx(&vm, &stack, &pc);
    vmClass->getField("count")->setInt(1024);
    Instruction getCount(j_getstatic, 0, 2);

    Interpreter interpreter;
    interpreter.invoke(&ctx, &getCount);

    ASSERT_EQ(1, stack.currentFrame()->getOperandStack()->size());
    ASSERT_EQ(1024, stack.currentFrame()->getOperandStack()->popInt());
}

TEST(Interperter, putStatic) {
    VirtualMachine vm("res", "com/vm/HelloWorld");
    
    auto vmClass = vm.getClass("com/op/FieldOperations");
    int pc = 0;
    VmStack stack;
    auto frame = std::unique_ptr<Frame>(new Frame(3, 3, vmClass->getRuntimeConstantPool(), nullptr));
    stack.push(std::move(frame));

    Context ctx(&vm, &stack, &pc);
    VmField* field = vmClass->getField("count");
    field->setInt(1024);
    stack.currentFrame()->getOperandStack()->pushInt(2048);
    Instruction setCount(j_putstatic, 0, 2);

    Interpreter interpreter;
    interpreter.invoke(&ctx, &setCount);

    ASSERT_EQ(0, stack.currentFrame()->getOperandStack()->size());
    ASSERT_EQ(2048, field->getInt());
}

TEST(Interperter, invokeStatic) {
    VirtualMachine vm("res", "com/vm/HelloWorld");
    Interpreter interpreter;
    auto vmClass = vm.getClass("com/op/NativeCall");

    int pc = 0;
    VmStack stack;
    auto frame = std::unique_ptr<Frame>(new Frame(3, 3, vmClass->getRuntimeConstantPool(), nullptr));
    stack.push(std::move(frame));

    Context ctx(&vm, &stack, &pc);

    Instruction setCount(j_invokestatic, 0, 2);
    interpreter.invoke(&ctx, &setCount);
}