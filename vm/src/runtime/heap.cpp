#include "vm/runtime/heap.h"
#include "vm/exceptions.h"

using namespace avm;

Heap::Heap(int size)
    :_freePosition(0),
     _maxSize(size),
     _data(new OBJECT_UNIT[size]) {

}

Heap::~Heap() {
    delete[] _data;
}

Object Heap::newInstance(const VmClass& type) {
    OBJECT_UNIT* startPos = _data;
    //FIXME:
    int totalSlots = type.getSize();
    if(_freePosition + totalSlots > _maxSize)
        throw OutOfMemoryException("Heap is full");
    _freePosition += totalSlots;
    return Object(startPos, totalSlots);
}