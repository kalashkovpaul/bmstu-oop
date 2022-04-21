#ifndef CONST_SET_ITERATOR_HPP_

#define CONST_SET_ITERATOR_HPP_

#include "ConstSetIterator.h"

template<typename T>
ConstSetIterator<T>::ConstSetIterator() {
    this->current.lock() = nullptr;
}

template<typename T>
ConstSetIterator<T>::ConstSetIterator(const std::shared_ptr<SetNode<T>>& node) {
    this->current.lock() = node;
}

template<typename T>
ConstSetIterator<T>::ConstSetIterator(const ConstSetIterator<T>& iterator) {
    this->current.lock() = iterator.current.lock();
}

template<typename T>
void ConstSetIterator<T>::setCurrent(SetNode<T>& node) {
    this->current = std::weak_ptr<SetNode>(node);
}

template<typename T>
SetNode<T>& ConstSetIterator<T>::getCurrent() {
    return *this->current.lock();
}

template<typename T>
SetNode<T>& ConstSetIterator<T>::getCurrent() const {
    return *this->current.lock();
}

template<typename T>
void ConstSetIterator<T>::next() {
    this->current = getCurrent().getNext();
}

template<typename T>
void ConstSetIterator<T>::previous() {
    this->current = getCurrent().getPrevious();
}

template<typename T>
const T* ConstSetIterator<T>::operator->() const {
    return getCurrent().get();
}

template<typename T>
const T& ConstSetIterator<T>::operator*() const {
    return getCurrent().value();
}

template<typename T>
ConstSetIterator<T>::operator bool() const {
    return this->current.lock() != nullptr;
}

template<typename T>
ConstSetIterator<T>& ConstSetIterator<T>::operator=(const ConstSetIterator<T>& iterator) {
    this->current = iterator.current.lock();
    return *this;
}

template<typename T>
ConstSetIterator<T>& ConstSetIterator<T>::operator++() {
    this->next();
    return *this;
}

template<typename T>
const ConstSetIterator<T>& ConstSetIterator<T>::operator++(int) {
    auto t = *this;
    this->next();
    return t;
}

template<typename T>
ConstSetIterator<T>& ConstSetIterator<T>::operator--() {
    this->previous();
    return *this;
}

template<typename T>
const ConstSetIterator<T>& ConstSetIterator<T>::operator--(int) {
    auto t = *this;
    this->previous();
    return t;
}

template<typename T>
bool ConstSetIterator<T>::operator!=(const ConstSetIterator<T>& iterator) const {
    return this->current.lock() != iterator.current.lock();
}

template<typename T>
bool ConstSetIterator<T>::operator!=(const ConstSetIterator<T>& iterator) const {
    return this->current.lock() == iterator.current.lock();
}

#endif