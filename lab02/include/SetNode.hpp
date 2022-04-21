#ifndef SET_NODE_HPP_

#define SET_NODE_HPP_

#include "SetNode.h"
#include "errors.h"

template<typename T>
SetNode<T>::SetNode(const T& data) {
    this->data = data;
}

template<typename T>
SetNode<T>::SetNode(std::shared_ptr<SetNode<T>>& node):
    SetNode<T>(node.data) {
    this->next = node.next;
}

template<typename T>
const T& SetNode<T>::getData() const {
    return this->data;
}

template<typename T>
void SetNode<T>::setData(const T& value) {
    this->data = value;
}

template<typename T>
void SetNode<T>::setNull() {
    this->next = nullptr;
    this->previous = nullptr;
}

template<typename T>
void SetNode<T>::exclude() {
    if (next) {
        next->prev = prev;
    }

    if (prev) {
        prev->next = next;
    }
    setNull();
}

template<typename T>
void SetNode<T>::setNext(const SetNode<T>& node) {
    this->next = std::make_shared<SetNode<T>>(node);
}

template<typename T>
void SetNode<T>::setNext(const std::shared_ptr<SetNode<T>>& node) {
    this->next = std::make_shared<SetNode<T>>(node);
}

template<typename T>
void SetNode<T>::setPrevious(const SetNode<T>& node) {
    this->previous = std::make_shared<SetNode<T>>(node);
}

template<typename T>
void SetNode<T>::setPrevious(const std::shared_ptr<SetNode<T>>& node) {
    this->previous = std::make_shared<SetNode<T>>(node);
}

template<typename T>
std::shared_ptr<SetNode<T>> SetNode<T>::getNext() const {
    return next;
}

template<typename T>
std::shared_ptr<SetNode<T>> SetNode<T>::getPrevious() const {
    return previous;
}

template<typename T>
bool SetNode<T>::operator==(const std::shared_ptr<SetNode<T>>& node) const {
    return this == node;
}

template<typename T>
bool SetNode<T>::operator!=(const std::shared_ptr<SetNode<T>>& node) const {
    return this != node;
}

template<typename T>
bool SetNode<T>::operator<(const std::shared_ptr<SetNode<T>>& node) const {
    return this->data < node.lock()->data;
}


#endif