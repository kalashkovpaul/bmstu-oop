#ifndef SET_H_

#define SET_H_

#include "BaseCollection.h"
#include "ConstSetIterator.h"
#include "SetNode.h"

#include <memory>
/*
TODO: 
Функции в нормальном порядке (с соответствием) - DONE
Итератор сделать безопасно, с пробрасыванием исключения. - DONE
Добавить конструктор для массива? - DONE 
В константных функциях проставить const (например, операторы) - DONE
Конструкторы сделать explicit - DONE
Итератор наследовать от bidirectional_tag - DONE
*/
template<typename T>
class Set: public BaseCollection {
public:
    Set() = default;
    explicit Set(const Set<T>& set);
    Set(Set<T>&& set) noexcept;
    explicit Set(const std::initializer_list<T> elements);
    Set(const T* array, size_t length);

    ~Set() override;

    bool has(const T& value) const;
    ConstSetIterator<T> find(const T& value) const;

    size_t capacity() const;
    
    void erase(const T& value);

    void clear() override;

    ConstSetIterator<T> begin() const;
    ConstSetIterator<T> end() const;

    bool add(const T& value);
    bool add(T&& value);
    void add(const std::initializer_list<T> elements);
    void add(T* array, size_t length);

    Set<T> update(const T& value) const;
    Set<T> update(T&& value) const;
    Set<T> update(const std::initializer_list<T> elements) const;
    Set<T> update(T* array, size_t length) const;

    Set<T> intersect(const Set<T>& set) const;
    Set<T> operator&(const Set<T>& set) const;
    Set<T>& operator&=(const Set<T>& set);

    Set<T> intersect(const std::initializer_list<T> elements) const;
    Set<T> operator&(const std::initializer_list<T> elements) const;
    Set<T>& operator&=(const std::initializer_list<T> elements);

    Set<T> unite(const Set<T>& set) const;
    Set<T> operator+(const Set<T>& set) const;
    Set<T>& operator+=(const Set<T>& set);
    Set<T> operator|(const Set<T>& set) const;
    Set<T>& operator|=(const Set<T>& set);

    Set<T> unite(const std::initializer_list<T> elements) const;
    Set<T> operator+(const std::initializer_list<T> elements) const;
    Set<T>& operator+=(const std::initializer_list<T> elements);
    Set<T> operator|(const std::initializer_list<T> elements) const;
    Set<T>& operator|=(const std::initializer_list<T> elements);

    Set<T> difference(const Set<T>& set) const;
    Set<T> operator-(const Set<T>& set) const;
    Set<T>& operator-=(const Set<T>& set);

    Set<T> difference(const std::initializer_list<T> elements) const;
    Set<T> operator-(const std::initializer_list<T> elements) const;
    Set<T>& operator-=(const std::initializer_list<T> elements);

    Set<T> symmetricDifference(const Set<T>& set)const;
    Set<T> operator^(const Set<T>& set) const;
    Set<T>& operator^=(const Set<T>& set);

    Set<T> symmetricDifference(const std::initializer_list<T> elements)const;
    Set<T> operator^(const std::initializer_list<T> elements) const;
    Set<T>& operator^=(const std::initializer_list<T> elements);

    Set<T>& assign(const Set<T>& set);
    Set<T>& operator=(const Set<T>& set);

    Set<T>& assign(const std::initializer_list<T> elements);
    Set<T>& operator=(const std::initializer_list<T> elements);

    Set<T>& assign(Set<T>&& set) noexcept;
    Set<T>& operator=(Set<T>&& set) noexcept;

    bool less(const Set<T>& set) const;
    bool operator<(const Set<T>& set) const;

    bool less(const std::initializer_list<T> elements) const;
    bool operator<(const std::initializer_list<T> elements) const;

    bool bigger(const Set<T>& set) const;
    bool operator>(const Set<T>& set) const;

    bool bigger(const std::initializer_list<T> elements) const;
    bool operator>(const std::initializer_list<T> elements) const;

    bool equal(const Set<T>& set) const;
    bool operator==(const Set<T>& set) const;

    bool equal(const std::initializer_list<T> elements) const;
    bool operator==(const std::initializer_list<T> elements) const;

    bool notEqual(const Set<T>& set) const;
    bool operator!=(const Set<T>& set) const;

    bool notEqual(const std::initializer_list<T> elements) const;
    bool operator!=(const std::initializer_list<T> elements) const;

protected:
    bool add(const std::shared_ptr<SetNode<T>>& node);

private:
    std::shared_ptr<SetNode<T>> head;
    std::shared_ptr<SetNode<T>> tail;
};

#include "Set.hpp"
#endif