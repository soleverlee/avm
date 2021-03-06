#ifndef _AVM_BYTECODE_INTERPRETER_H_
#define _AVM_BYTECODE_INTERPRETER_H_

#include "class_file/format/instruction.h"
#include "vm/runtime/vm_field.h"
#include "vm/runtime/vm_method.h"

namespace avm {
class Context;
class VmThread;
class VirtualMachine;
class VmStack;
class Frame;
class Interpreter {
public:
    Interpreter();
    virtual ~Interpreter();
public:
    static VmField* lookupField(Context& context, const u2 fieldRefIndex);
    static VmMethod* lookupMethod(Context& context, const u2 methodRefIndex);
    static void checkContext(Context& context);
public:
    void execute(const VmMethod* method, VirtualMachine& jvm, VmStack& stack);
    void invokeMain(const VmMethod* method, VirtualMachine& jvm, VmStack& stack, std::vector<std::string> args);
    void invoke(const VmMethod* method, VirtualMachine& jvm, VmStack& stack);
    void invoke(Context* context, const Instruction* instruction);
    void invokeNative(const VmMethod* method, VirtualMachine& jvm, VmStack& stack);
};

void invoke_nop             (Context& context, const Instruction* instruction);
void invoke_aconst_null     (Context& context, const Instruction* instruction);
void invoke_iconst_m1       (Context& context, const Instruction* instruction);
void invoke_iconst_0        (Context& context, const Instruction* instruction);
void invoke_iconst_1        (Context& context, const Instruction* instruction);
void invoke_iconst_2        (Context& context, const Instruction* instruction);
void invoke_iconst_3        (Context& context, const Instruction* instruction);
void invoke_iconst_4        (Context& context, const Instruction* instruction);
void invoke_iconst_5        (Context& context, const Instruction* instruction);
void invoke_lconst_0        (Context& context, const Instruction* instruction);
void invoke_lconst_1        (Context& context, const Instruction* instruction);
void invoke_fconst_0        (Context& context, const Instruction* instruction);
void invoke_fconst_1        (Context& context, const Instruction* instruction);
void invoke_fconst_2        (Context& context, const Instruction* instruction);
void invoke_dconst_0        (Context& context, const Instruction* instruction);
void invoke_dconst_1        (Context& context, const Instruction* instruction);
void invoke_bipush          (Context& context, const Instruction* instruction);
void invoke_sipush          (Context& context, const Instruction* instruction);
void invoke_ldc             (Context& context, const Instruction* instruction);
void invoke_ldc_w           (Context& context, const Instruction* instruction);
void invoke_ldc2_w          (Context& context, const Instruction* instruction);
void invoke_iload           (Context& context, const Instruction* instruction);
void invoke_lload           (Context& context, const Instruction* instruction);
void invoke_fload           (Context& context, const Instruction* instruction);
void invoke_dload           (Context& context, const Instruction* instruction);
void invoke_aload           (Context& context, const Instruction* instruction);
void invoke_iload_0         (Context& context, const Instruction* instruction);
void invoke_iload_1         (Context& context, const Instruction* instruction);
void invoke_iload_2         (Context& context, const Instruction* instruction);
void invoke_iload_3         (Context& context, const Instruction* instruction);
void invoke_lload_0         (Context& context, const Instruction* instruction);
void invoke_lload_1         (Context& context, const Instruction* instruction);
void invoke_lload_2         (Context& context, const Instruction* instruction);
void invoke_lload_3         (Context& context, const Instruction* instruction);
void invoke_fload_0         (Context& context, const Instruction* instruction);
void invoke_fload_1         (Context& context, const Instruction* instruction);
void invoke_fload_2         (Context& context, const Instruction* instruction);
void invoke_fload_3         (Context& context, const Instruction* instruction);
void invoke_dload_0         (Context& context, const Instruction* instruction);
void invoke_dload_1         (Context& context, const Instruction* instruction);
void invoke_dload_2         (Context& context, const Instruction* instruction);
void invoke_dload_3         (Context& context, const Instruction* instruction);
void invoke_aload_0         (Context& context, const Instruction* instruction);
void invoke_aload_1         (Context& context, const Instruction* instruction);
void invoke_aload_2         (Context& context, const Instruction* instruction);
void invoke_aload_3         (Context& context, const Instruction* instruction);
void invoke_iaload          (Context& context, const Instruction* instruction);
void invoke_laload          (Context& context, const Instruction* instruction);
void invoke_faload          (Context& context, const Instruction* instruction);
void invoke_daload          (Context& context, const Instruction* instruction);
void invoke_aaload          (Context& context, const Instruction* instruction);
void invoke_baload          (Context& context, const Instruction* instruction);
void invoke_caload          (Context& context, const Instruction* instruction);
void invoke_saload          (Context& context, const Instruction* instruction);
void invoke_istore          (Context& context, const Instruction* instruction);
void invoke_lstore          (Context& context, const Instruction* instruction);
void invoke_fstore          (Context& context, const Instruction* instruction);
void invoke_dstore          (Context& context, const Instruction* instruction);
void invoke_astore          (Context& context, const Instruction* instruction);
void invoke_istore_0        (Context& context, const Instruction* instruction);
void invoke_istore_1        (Context& context, const Instruction* instruction);
void invoke_istore_2        (Context& context, const Instruction* instruction);
void invoke_istore_3        (Context& context, const Instruction* instruction);
void invoke_lstore_0        (Context& context, const Instruction* instruction);
void invoke_lstore_1        (Context& context, const Instruction* instruction);
void invoke_lstore_2        (Context& context, const Instruction* instruction);
void invoke_lstore_3        (Context& context, const Instruction* instruction);
void invoke_fstore_0        (Context& context, const Instruction* instruction);
void invoke_fstore_1        (Context& context, const Instruction* instruction);
void invoke_fstore_2        (Context& context, const Instruction* instruction);
void invoke_fstore_3        (Context& context, const Instruction* instruction);
void invoke_dstore_0        (Context& context, const Instruction* instruction);
void invoke_dstore_1        (Context& context, const Instruction* instruction);
void invoke_dstore_2        (Context& context, const Instruction* instruction);
void invoke_dstore_3        (Context& context, const Instruction* instruction);
void invoke_astore_0        (Context& context, const Instruction* instruction);
void invoke_astore_1        (Context& context, const Instruction* instruction);
void invoke_astore_2        (Context& context, const Instruction* instruction);
void invoke_astore_3        (Context& context, const Instruction* instruction);
void invoke_iastore         (Context& context, const Instruction* instruction);
void invoke_lastore         (Context& context, const Instruction* instruction);
void invoke_fastore         (Context& context, const Instruction* instruction);
void invoke_dastore         (Context& context, const Instruction* instruction);
void invoke_aastore         (Context& context, const Instruction* instruction);
void invoke_bastore         (Context& context, const Instruction* instruction);
void invoke_castore         (Context& context, const Instruction* instruction);
void invoke_sastore         (Context& context, const Instruction* instruction);
void invoke_pop             (Context& context, const Instruction* instruction);
void invoke_pop2            (Context& context, const Instruction* instruction);
void invoke_dup             (Context& context, const Instruction* instruction);
void invoke_dup_x1          (Context& context, const Instruction* instruction);
void invoke_dup_x2          (Context& context, const Instruction* instruction);
void invoke_dup2            (Context& context, const Instruction* instruction);
void invoke_dup2_x1         (Context& context, const Instruction* instruction);
void invoke_dup2_x2         (Context& context, const Instruction* instruction);
void invoke_swap            (Context& context, const Instruction* instruction);
void invoke_iadd            (Context& context, const Instruction* instruction);
void invoke_ladd            (Context& context, const Instruction* instruction);
void invoke_fadd            (Context& context, const Instruction* instruction);
void invoke_dadd            (Context& context, const Instruction* instruction);
void invoke_isub            (Context& context, const Instruction* instruction);
void invoke_lsub            (Context& context, const Instruction* instruction);
void invoke_fsub            (Context& context, const Instruction* instruction);
void invoke_dsub            (Context& context, const Instruction* instruction);
void invoke_imul            (Context& context, const Instruction* instruction);
void invoke_lmul            (Context& context, const Instruction* instruction);
void invoke_fmul            (Context& context, const Instruction* instruction);
void invoke_dmul            (Context& context, const Instruction* instruction);
void invoke_idiv            (Context& context, const Instruction* instruction);
void invoke_ldiv            (Context& context, const Instruction* instruction);
void invoke_fdiv            (Context& context, const Instruction* instruction);
void invoke_ddiv            (Context& context, const Instruction* instruction);
void invoke_irem            (Context& context, const Instruction* instruction);
void invoke_lrem            (Context& context, const Instruction* instruction);
void invoke_frem            (Context& context, const Instruction* instruction);
void invoke_drem            (Context& context, const Instruction* instruction);
void invoke_ineg            (Context& context, const Instruction* instruction);
void invoke_lneg            (Context& context, const Instruction* instruction);
void invoke_fneg            (Context& context, const Instruction* instruction);
void invoke_dneg            (Context& context, const Instruction* instruction);
void invoke_ishl            (Context& context, const Instruction* instruction);
void invoke_lshl            (Context& context, const Instruction* instruction);
void invoke_ishr            (Context& context, const Instruction* instruction);
void invoke_lshr            (Context& context, const Instruction* instruction);
void invoke_iushr           (Context& context, const Instruction* instruction);
void invoke_lushr           (Context& context, const Instruction* instruction);
void invoke_iand            (Context& context, const Instruction* instruction);
void invoke_land            (Context& context, const Instruction* instruction);
void invoke_ior             (Context& context, const Instruction* instruction);
void invoke_lor             (Context& context, const Instruction* instruction);
void invoke_ixor            (Context& context, const Instruction* instruction);
void invoke_lxor            (Context& context, const Instruction* instruction);
void invoke_iinc            (Context& context, const Instruction* instruction);
void invoke_i2l             (Context& context, const Instruction* instruction);
void invoke_i2f             (Context& context, const Instruction* instruction);
void invoke_i2d             (Context& context, const Instruction* instruction);
void invoke_l2i             (Context& context, const Instruction* instruction);
void invoke_l2f             (Context& context, const Instruction* instruction);
void invoke_l2d             (Context& context, const Instruction* instruction);
void invoke_f2i             (Context& context, const Instruction* instruction);
void invoke_f2l             (Context& context, const Instruction* instruction);
void invoke_f2d             (Context& context, const Instruction* instruction);
void invoke_d2i             (Context& context, const Instruction* instruction);
void invoke_d2l             (Context& context, const Instruction* instruction);
void invoke_d2f             (Context& context, const Instruction* instruction);
void invoke_i2b             (Context& context, const Instruction* instruction);
void invoke_i2c             (Context& context, const Instruction* instruction);
void invoke_i2s             (Context& context, const Instruction* instruction);
void invoke_lcmp            (Context& context, const Instruction* instruction);
void invoke_fcmpl           (Context& context, const Instruction* instruction);
void invoke_fcmpg           (Context& context, const Instruction* instruction);
void invoke_dcmpl           (Context& context, const Instruction* instruction);
void invoke_dcmpg           (Context& context, const Instruction* instruction);
void invoke_ifeq            (Context& context, const Instruction* instruction);
void invoke_ifne            (Context& context, const Instruction* instruction);
void invoke_iflt            (Context& context, const Instruction* instruction);
void invoke_ifge            (Context& context, const Instruction* instruction);
void invoke_ifgt            (Context& context, const Instruction* instruction);
void invoke_ifle            (Context& context, const Instruction* instruction);
void invoke_if_icmpeq       (Context& context, const Instruction* instruction);
void invoke_if_icmpne       (Context& context, const Instruction* instruction);
void invoke_if_icmplt       (Context& context, const Instruction* instruction);
void invoke_if_icmpge       (Context& context, const Instruction* instruction);
void invoke_if_icmpgt       (Context& context, const Instruction* instruction);
void invoke_if_icmple       (Context& context, const Instruction* instruction);
void invoke_if_acmpeq       (Context& context, const Instruction* instruction);
void invoke_if_acmpne       (Context& context, const Instruction* instruction);
void invoke_goto            (Context& context, const Instruction* instruction);
void invoke_jsr             (Context& context, const Instruction* instruction);
void invoke_ret             (Context& context, const Instruction* instruction);
void invoke_tableswitch     (Context& context, const Instruction* instruction);
void invoke_lookupswitch    (Context& context, const Instruction* instruction);
void invoke_ireturn         (Context& context, const Instruction* instruction);
void invoke_lreturn         (Context& context, const Instruction* instruction);
void invoke_freturn         (Context& context, const Instruction* instruction);
void invoke_dreturn         (Context& context, const Instruction* instruction);
void invoke_areturn         (Context& context, const Instruction* instruction);
void invoke_return          (Context& context, const Instruction* instruction);
void invoke_getstatic       (Context& context, const Instruction* instruction);
void invoke_putstatic       (Context& context, const Instruction* instruction);
void invoke_getfield        (Context& context, const Instruction* instruction);
void invoke_putfield        (Context& context, const Instruction* instruction);
void invoke_invokevirtual   (Context& context, const Instruction* instruction);
void invoke_invokespecial   (Context& context, const Instruction* instruction);
void invoke_invokestatic    (Context& context, const Instruction* instruction);
void invoke_invokeinterface (Context& context, const Instruction* instruction);
void invoke_invokedynamic   (Context& context, const Instruction* instruction);
void invoke_new             (Context& context, const Instruction* instruction);
void invoke_newarray        (Context& context, const Instruction* instruction);
void invoke_anewarray       (Context& context, const Instruction* instruction);
void invoke_arraylength     (Context& context, const Instruction* instruction);
void invoke_athrow          (Context& context, const Instruction* instruction);
void invoke_checkcast       (Context& context, const Instruction* instruction);
void invoke_instanceof      (Context& context, const Instruction* instruction);
void invoke_monitorenter    (Context& context, const Instruction* instruction);
void invoke_monitorexit     (Context& context, const Instruction* instruction);
void invoke_wide            (Context& context, const Instruction* instruction);
void invoke_multianewarray  (Context& context, const Instruction* instruction);
void invoke_ifnull          (Context& context, const Instruction* instruction);
void invoke_ifnonnull       (Context& context, const Instruction* instruction);
void invoke_goto_w          (Context& context, const Instruction* instruction);
void invoke_jsr_w           (Context& context, const Instruction* instruction);
void invoke_breakpoint      (Context& context, const Instruction* instruction);
void invoke_impdep1         (Context& context, const Instruction* instruction);
void invoke_impdep2         (Context& context, const Instruction* instruction);
}
#endif