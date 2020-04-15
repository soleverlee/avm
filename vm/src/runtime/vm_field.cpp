#include "vm/runtime/vm_field.h"
#include "vm/util/numbers.h"

using namespace avm;

VmField::VmField(const std::string &name, const std::string &descriptor)
    : _name(name),
      _descriptor(descriptor),
      _slot1(nullptr),
      _slot2(nullptr) {
}

VmField::~VmField() {
}

void VmField::setByte(int8_t value) {
    _slot1 = std::unique_ptr<Slot>(new Slot(value));
}
void VmField::setShort(int16_t value) {
    _slot1 = std::unique_ptr<Slot>(new Slot(value));
}
void VmField::setInt(int32_t value) {
    _slot1 = std::unique_ptr<Slot>(new Slot(value));
}
void VmField::setLong(int64_t value) {
    uint32_t highBytes, lowBytes;
    std::tie(highBytes, lowBytes) = Numbers::splitLong(value);
    _slot1 = std::unique_ptr<Slot>(new Slot(highBytes));
    _slot2 = std::unique_ptr<Slot>(new Slot(lowBytes));
}
void VmField::setFloat(float value) {
    int32_t *sv = reinterpret_cast<int32_t*>(&value);
    _slot1 = std::unique_ptr<Slot>(new Slot(*sv));
}
void VmField::setDouble(double value) {
    uint32_t highBytes, lowBytes;
    std::tie(highBytes, lowBytes) = Numbers::splitDouble(value);
    _slot1 = std::unique_ptr<Slot>(new Slot(highBytes));
    _slot2 = std::unique_ptr<Slot>(new Slot(lowBytes));
}
void VmField::setChar(uint16_t value) {
    _slot1 = std::unique_ptr<Slot>(new Slot(value));
}
int8_t VmField::getByte() {
    return _slot1.get()->asInt();
}
int16_t VmField::getShort() {
    return _slot1.get()->asInt();
}
int32_t VmField::getInt() {
    return _slot1.get()->asInt();
}
int64_t VmField::getLong() {
    uint32_t highBytes = _slot1.get()->asInt();
    uint32_t lowBytes = _slot2.get()->asInt();
    return Numbers::asLong(highBytes, lowBytes);
}
float VmField::getFloat() {
    return _slot1.get()->asFloat();
}
double VmField::getDouble() {
    uint32_t highBytes = _slot1.get()->asInt();
    uint32_t lowBytes = _slot2.get()->asInt();
    return Numbers::asDouble(highBytes, lowBytes);
}
uint16_t VmField::getChar() {
    return _slot1.get()->asInt();
}

std::string VmField::getString() {
    return *reinterpret_cast<const std::string*>(getLong());
}