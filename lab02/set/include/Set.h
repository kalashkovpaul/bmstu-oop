#ifndef SET_H_

#define SET_H_

#include "BaseCollection.h"
#include "ConstSetIterator.h"
#include "SetNode.h"

#include <memory>

template<typename T>
class Set: public BaseCollection {
public:
    Set() = default;
    Set(const Set<T>& set) noexcept(false);
    Set(Set<T>&& set) noexcept;
    Set(const std::initializer_list<T> elements);

    ~Set() override;

    bool has(const T& value) const;
    ConstSetIterator<T> find(const T& value) const;

    size_t getSize() const;
    
    void erase(const T& value);
    void erase(const ConstSetIterator<T>& iterator);

    void clear() override;

    ConstSetIterator<T> begin() const;
    ConstSetIterator<T> end() const;

    bool add(const T& value) noexcept(false);
    bool add(T&& value) noexcept(false);
    void add(const std::initializer_list<T> elements) noexcept(false);
    void add(T* array, size_t length) noexcept(false);

    Set<T> update(const T& value) noexcept(false);
    Set<T> update(T&& value) noexcept(false);
    Set<T> update(const std::initializer_list<T> elements) noexcept(false);
    Set<T> update(T* array, size_t length) noexcept (false);

    Set<T> operator&(const Set<T>& set);
    Set<T> intersect(const Set<T>& set);

    Set<T>& operator+=(const Set<T>& set);
    Set<T>& operator|=(const Set<T>& set);
    Set<T> operator+(const Set<T>& set);
    Set<T> operator|(const Set<T>& set);
    Set<T> unite(const Set<T>& set);

    Set<T> operator-(const Set<T>& set);
    Set<T> difference(const Set<T>& set);
    Set<T>& operator-=(const Set<T>& set);

    Set<T> operator^(const Set<T>& set);
    Set<T> symmetricDifference(const Set<T>& set);
    Set<T>& operator^=(const Set<T>& set);


    Set<T>& operator=(const Set<T> set) noexcept(false);
    Set<T>& operator=(Set<T>&& set) noexcept;

    bool operator==(const Set<T> set) const;
    bool operator!=(const Set<T> set) const;

protected:
    bool add(const std::shared_ptr<SetNode<T>>& node) noexcept(false);

private:
    std::shared_ptr<SetNode<T>> head;
    std::shared_ptr<SetNode<T>> tail;
};

#include "Set.hpp"
#endif