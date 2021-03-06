#ifndef _AVM_OPERAND_STACK_H_
#define _AVM_OPERAND_STACK_H_

#include "slot.h"
#include "vm_field.h"

#include <cstdint>
#include <stack>

namespace avm {
class OperandStack {
public:
    OperandStack(int maxSize);
    virtual ~OperandStack();
public:
    void pushByte(int8_t value);
    void pushShort(int16_t value);
    void pushInt(int32_t value);
    void pushLong(int64_t value);
    void pushFloat(float value);
    void pushDouble(double value);
    void pushChar(uint16_t value);
    void pushReference(reference value);
    int8_t popByte();
    int16_t popShort();
    int32_t popInt();
    int64_t popLong();
    float popFloat();
    double popDouble();
    uint16_t popChar();
    reference popReference();
public:
    void pushField(const VmField* field);
    void popField(VmField* field);
    inline int size() const {
        return _variables.size();
    }
    void dump() const;
protected:
    void checkStackSize(int valueSize);
    void pushUnit(SLOT value);
    void pushTwoUnits(int64_t value);
    SLOT popUnit();
    int64_t popTwoUnits();
protected:
    int _maxSize;
    std::stack<SLOT> _variables;
};
}
#endif
