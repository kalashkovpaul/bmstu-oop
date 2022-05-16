#ifndef CONST_SET_ITERATOR_HPP_

#define CONST_SET_ITERATOR_HPP_

#include <chrono>

#include "ConstSetIterator.h"
#include "errors.h"

template<typename T>
ConstSetIterator<T>::ConstSetIterator() {
    this->current.lock() = nullptr;
}

template<typename T>
ConstSetIterator<T>::ConstSetIterator(const std::shared_ptr<SetNode<T>>& node) {
    this->current = node;
}

template<typename T>
ConstSetIterator<T>::ConstSetIterator(const ConstSetIterator<T>& iterator) {
    checkExpired(__FUNCTION__);
    this->current = iterator.current.lock();
}

template<typename T>
SetNode<T>& ConstSetIterator<T>::getCurrent() {
    checkExpired(__FUNCTION__);

    return *this->current.lock();
}

template<typename T>
SetNode<T>& ConstSetIterator<T>::getCurrent() const {
    checkExpired(__FUNCTION__);

    return *this->current.lock();
}

template<typename T>
void ConstSetIterator<T>::next() {
    checkExpired(__FUNCTION__);

    this->current = getCurrent().getNext();
}

template<typename T>
void ConstSetIterator<T>::previous() {
    checkExpired(__FUNCTION__);

    this->current = getCurrent().getPrevious();
}

template<typename T>
const T* ConstSetIterator<T>::operator->() const {
    checkExpired(__FUNCTION__);

    return getCurrent().get();
}

template<typename T>
const T& ConstSetIterator<T>::operator*() const {
    checkExpired(__FUNCTION__);

    return getCurrent().value();
}

template<typename T>
ConstSetIterator<T>::operator bool() const {
    checkExpired(__FUNCTION__);

    return this->current.lock() != nullptr;
}

template<typename T>
ConstSetIterator<T>& ConstSetIterator<T>::operator=(const ConstSetIterator<T>& iterator) {
    checkExpired(__FUNCTION__);
    iterator.checkExpired(__FUNCTION__);
    this->current = iterator.current.lock();
    return *this;
}

template<typename T>
ConstSetIterator<T>& ConstSetIterator<T>::operator++() {
    checkExpired(__FUNCTION__);

    this->next();
    return *this;
}

template<typename T>
const ConstSetIterator<T> ConstSetIterator<T>::operator++(int) {
    checkExpired(__FUNCTION__);

    auto t = *this;
    this->next();
    return t;
}

template<typename T>
ConstSetIterator<T>& ConstSetIterator<T>::operator--() {
    checkExpired(__FUNCTION__);

    this->previous();
    return *this;
}

template<typename T>
const ConstSetIterator<T> ConstSetIterator<T>::operator--(int) {
    checkExpired(__FUNCTION__);

    auto t = *this;
    this->previous();
    return t;
}

template<typename T>
bool ConstSetIterator<T>::operator!=(const ConstSetIterator<T>& iterator) const {
    checkExpired(__FUNCTION__);
    iterator.checkExpired(__FUNCTION__);
    return this->current.lock() != iterator.current.lock();
}

template<typename T>
bool ConstSetIterator<T>::operator==(const ConstSetIterator<T>& iterator) const {
    checkExpired(__FUNCTION__);
    iterator.checkExpired(__FUNCTION__);
    return this->current.lock() == iterator.current.lock();
}

template<typename T>
void ConstSetIterator<T>::checkExpired(const std::string function) const {
    if (current.expired() && current.lock()) {
        auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw new IteratorError(ctime(&t), __FILE__, typeid(ConstSetIterator).name(), function);
    }
}

#endif