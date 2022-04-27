#ifndef SET_HPP_

#define SET_HPP_

#include <chrono>
#include "Set.h"
#include "errors.h"

template<typename T>
Set<T>::Set(const Set<T>& set): Set() {
    for (auto i = set.begin(); i != set.end(); ++i) {
        std::shared_ptr<SetNode<T>> tmpNode = nullptr;
        try {
            tmpNode = std::shared_ptr<SetNode<T>>(new SetNode<T>);
        } catch (std::bad_alloc &error) {
            auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            throw BadAllocError(ctime(&t), __FILE__, typeid(Set).name(), __FUNCTION__);
        }
        tmpNode->setData(*i);
        add(tmpNode);
    } 
}

template<typename T>
Set<T>::Set(Set<T>&& set) noexcept {
    size = set.size;
    head = set.head;
}

template<typename T>
Set<T>::Set(const std::initializer_list<T> elements): Set() {
    for (auto &el: elements) {
        std::shared_ptr<SetNode<T>> tmpNode = nullptr;
        try {
            tmpNode = std::shared_ptr<SetNode<T>>(new SetNode<T>);
        } catch (std::bad_alloc &error) {
            auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            throw BadAllocError(ctime(&t), __FILE__, typeid(Set).name(), __FUNCTION__);
        }
        tmpNode->setData(el);
        add(tmpNode);
    } 
}

template<typename T>
Set<T>::Set(const T* array, size_t length) {
    for (size_t i = 0; i < length; i++) {
        std::shared_ptr<SetNode<T>> tmpNode = nullptr;
        try {
            tmpNode = std::shared_ptr<SetNode<T>>(new SetNode<T>);
        } catch (std::bad_alloc &error) {
            auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            throw BadAllocError(ctime(&t), __FILE__, typeid(Set).name(), __FUNCTION__);
        }
        tmpNode->setData(array[i]);
        add(tmpNode);
    } 
}

template<typename T>
Set<T>::~Set() {
    this->clear();
}

template<typename T>
bool Set<T>::has(const T& value) const {
    for (auto el = begin(); el != end(); ++el) {
        if (value == *el) 
            return true;
    }
    return false;
}

template<typename T>
ConstSetIterator<T> Set<T>::find(const T& value) const {
    for (auto el = begin(); el != end(); ++el) {
        if (value == *el) 
            return ConstSetIterator<T>(el);
    }
    return end();
}

template<typename T>
size_t Set<T>::capacity() const {
    return size;
}

template<typename T>
void Set<T>::erase(const T& value) {
    auto t = find(value);
    if (t) {
        erase(t);
    }
}

template<typename T>
void Set<T>::erase(const ConstSetIterator<T>& iterator) {
    if (!size) {
        return;
    }
    if (!iterator) {
        auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw IteratorError(ctime(&t), __FILE__, typeid(Set).name(), __FUNCTION__);
    }

    auto t = std::make_shared<SetNode<T>>(iterator.getCurrent());
    if (head->getData() == t->getData()) {
        head = t->getNext();
    }
    t->exclude();
    size--;
}

template<typename T>
ConstSetIterator<T> Set<T>::begin() const {
    return ConstSetIterator<T>(head);
}

template<typename T>
ConstSetIterator<T> Set<T>::end() const {
    return ConstSetIterator<T>(tail ? tail->getNext() : nullptr);
}

template<typename T>
bool Set<T>::add(const T& value) {
    std::shared_ptr<SetNode<T>> tmpNode;
    try {
        tmpNode = std::shared_ptr<SetNode<T>>(new SetNode<T>);
    } catch (std::bad_alloc &error) {
        auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw BadAllocError(ctime(&t), __FILE__, typeid(Set).name(), __FUNCTION__);
    }
    tmpNode->setData(value);
    return add(tmpNode);
}

template<typename T>
bool Set<T>::add(T&& value) {
    std::shared_ptr<SetNode<T>> tmpNode;
    try {
        tmpNode = std::shared_ptr<SetNode<T>>(new SetNode<T>);
    } catch (std::bad_alloc &error) {
        auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw BadAllocError(ctime(&t), __FILE__, typeid(Set).name(), __FUNCTION__);
    }
    tmpNode->setData(value);
    return add(tmpNode);
}

template<typename T>
bool Set<T>::add(const std::shared_ptr<SetNode<T>>& node) {
    std::shared_ptr<SetNode<T>> tmpNode;
    try {
        tmpNode = std::shared_ptr<SetNode<T>>(new SetNode<T>);
    } catch (std::bad_alloc &error) {
        auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw BadAllocError(ctime(&t), __FILE__, typeid(Set).name(), __FUNCTION__);
    }
    tmpNode->setData(node->getData());
    if (!size) {
        head = tmpNode;
        tail = tmpNode;
        size++;
        return true;
    }
    if (find(tmpNode->getData()))
        return false;
    tmpNode->setPrevious(tail);
    tail->setNext(tmpNode);
    tail = tmpNode;
    size++;
    return true;
}

template<typename T>
void Set<T>::add(const std::initializer_list<T> elements) {
    for (auto &el: elements) {
        std::shared_ptr<SetNode<T>> tmpNode = nullptr;
        try {
            tmpNode = std::shared_ptr<SetNode<T>>(new SetNode<T>);
        } catch (std::bad_alloc &error) {
            auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            throw BadAllocError(ctime(&t), __FILE__, typeid(Set).name(), __FUNCTION__);
        }
        tmpNode->setData(el);
        add(tmpNode);
    } 
}

template<typename T>
void Set<T>::add(T* array, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        add(array[i]);
    }
}

template<typename T>
Set<T> Set<T>::update(const T& value) const {
    Set<T> result(*this);
    result.add(value);
    return result;
}

template<typename T>
Set<T> Set<T>::update(T&& value) const {
    Set<T> result(*this);
    result.add(value);
    return result;
}

template<typename T>
Set<T> Set<T>::update(const std::initializer_list<T> elements) const {
    Set<T> result(*this);
    for (auto& el : elements) {
        result.add(el);
    }
    return result;
}

template<typename T>
Set<T> Set<T>::update(T* array, size_t length) const {
    Set<T> result(*this);
    for (size_t i = 0; i < length; ++i) {
        result.add(array[i]);
    }
    return result;
}

template<typename T>
Set<T> Set<T>::operator&(const Set<T>& set) const {
    Set<T> result;
    for (auto i : *this) {
        if (set.find(i)) {
            result.add(i);
        }
    }
    return result;
}

template<typename T>
Set<T>& Set<T>::operator&=(const Set<T>& set) {
    for (auto i : *this) {
        if (find(i)) {
            add(i);
        }
    }
    return *this;
}

template<typename T>
Set<T> Set<T>::intersect(const Set<T>& set) const {
    return *this & set;
}

template<typename T>
Set<T>& Set<T>::operator+=(const Set<T>& set) {
    for (auto i : set) {
        if (!find(i)) {
            add(i);
        }
    }
    return *this;
}

template<typename T>
Set<T>& Set<T>::operator|=(const Set<T>& set) {
    *this += set;
    return *this;
}

template<typename T>
Set<T> Set<T>::operator+(const Set<T>& set) const {
    Set<T> result(*this);
    result += set;
    return result;
}

template<typename T>
Set<T> Set<T>::operator|(const Set<T>& set) const {
    return *this + set;
}

template<typename T>
Set<T> Set<T>::unite(const Set<T>& set) const {
    return *this | set;
}

template<typename T>
Set<T> Set<T>::operator-(const Set<T>& set) const {
    Set<T> result;
    for (auto i : *this) {
        result.add(i);
    }
    for (auto i : set) {
        result.erase(i);
    }
    return result;
}

template<typename T>
Set<T> Set<T>::difference(const Set<T>& set) const {
    return *this - set;
}

template<typename T>
Set<T>& Set<T>::operator-=(const Set<T>& set) {
    for (auto i = set.begin(); i != set.end(); ++i) {
        erase(*i);
    }
    return *this;
}

template<typename T>
Set<T> Set<T>::operator^(const Set<T>& set) const {
    Set<T> result;
    for (auto i : *this) {
        if (!set.find(i)) {
            result.add(i);
        }
    }
    for (auto i : set) {
        if (!find(i)) {
            result.add(i);
        }
    }
    return result;
}

template<typename T>
Set<T> Set<T>::symmetricDifference(const Set<T>& set) const {
    return *this ^ set;
}

template<typename T>
Set<T>& Set<T>::operator^=(const Set<T>& set) {
    Set<T> tmp = *this ^ set;
    clear();
    for (auto i : tmp) {
        add(i);
    }
    return *this;
}

template<typename T>
Set<T>& Set<T>::operator=(const Set<T>& set) {
    if (&set == this) {
        return *this;
    }
    clear();
    size = 0;
    head = nullptr;
    tail = nullptr;
    for (auto i = set.begin(); i != set.end(); ++i) {
        std::shared_ptr<SetNode<T>> tmpNode = nullptr;
        try {
            tmpNode = std::shared_ptr<SetNode<T>>(new SetNode<T>);
        } catch (std::bad_alloc &error) {
            auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            throw BadAllocError(ctime(&t), __FILE__, typeid(set).name(), __FUNCTION__);
        }
        tmpNode->setData(*i);
        add(tmpNode);
    }
    return *this;
}

template<typename T>
Set<T>& Set<T>::operator=(Set<T>&& set) noexcept {
    size = set.size;
    head = set.head;
    tail = set.tail;
    return *this;
}

template<typename T>
bool Set<T>::operator==(const Set<T>& set) const {
    if (size != set.size) {
        return false;
    }
    for (auto i : set) {
        if (!find(i)) {
            return false;
        }
    }
    return true;
}

template<typename T>
bool Set<T>::operator!=(const Set<T>& set) const {
    return !(*this == set);
}

template<typename T>
std::ostream& operator<<(std::ostream &os, Set<T> &set) {
    for (auto i = set.begin(); i != set.end(); ++i) {
        os << *i << " ";
    }
    return os;
}

template<typename T>
void Set<T>::clear() {
    while (head) {
        auto t = head;
        head = head->getNext();
        t->setNext(nullptr);
        t = tail;
        tail = tail->getPrevious();
        t->setPrevious(nullptr);
    }
    size = 0;
}

template<typename T>
std::ostream& operator<<(std::ostream &os, const Set<T> &set) {
    for (auto i = set.begin(); i != set.end(); ++i) {
        os << *i << " ";
    }
    return os;
}

#endif