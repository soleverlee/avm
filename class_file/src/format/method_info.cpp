#include "class_file/format/method_info.h"
#include "class_file/exceptions.h"

using namespace avm;

MethodInfo::MethodInfo() {

}

MethodInfo::~MethodInfo() {
}

const Code* MethodInfo::getCode() const {
    return (Code*) getAttrinute(AttributeType::CODE);
}

const Exceptions* MethodInfo::getExceptions() const {
    return (Exceptions*) getAttrinute(AttributeType::EXCEPTIONS);
}