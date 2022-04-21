#include "BaseCollection.h"

BaseCollection::~BaseCollection() = default;

bool BaseCollection::isEmpty() const {
    return size == 0;
}

void BaseCollection::clear() {
    size = 0;
}