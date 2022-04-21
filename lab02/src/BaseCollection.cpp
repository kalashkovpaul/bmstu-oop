#include "BaseCollection.h"

BaseCollection::~BaseCollection() = default;

bool BaseCollection::isEmpty() const {
    return size == 0;
}