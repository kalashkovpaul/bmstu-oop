#ifndef CONST_SET_ITERATOR_H_

#define CONST_SET_ITERATOR_H_

#include "Set.h"
#include "SetNode.h"
#include <iterator>

template<typename T>
class ConstSetIterator: public std::iterator<std::input_iterator_tag, T> {
public:
    ConstSetIterator();
    explicit ConstSetIterator(const std::shared_ptr<SetNode<T>>& node);
    ConstSetIterator(const ConstSetIterator<T>& iterator);

    ~ConstSetIterator() = default;

    virtual void next();
    virtual void previous();

    const T* operator->() const;
    const T& operator*() const;

    explicit operator bool() const;

    ConstSetIterator<T>& operator=(const ConstSetIterator<T>& iterator);

    virtual ConstSetIterator<T>& operator++();
    virtual const ConstSetIterator<T> operator++(int);
    virtual ConstSetIterator<T>& operator--();
    virtual const ConstSetIterator<T> operator--(int);

    bool operator!=(const ConstSetIterator<T>& iterator) const;
    bool operator==(const ConstSetIterator<T>& iterator) const;

    template<typename U>
    friend class Set;

protected:
    virtual SetNode<T>& getCurrent();
    virtual SetNode<T>& getCurrent() const;

private:
    std::weak_ptr<SetNode<T>> current;
};

#include "ConstSetIterator.hpp"

#endif