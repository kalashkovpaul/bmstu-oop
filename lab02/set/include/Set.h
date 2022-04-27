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
Для двух итераторов? - TODO?
В константных функциях проставить const (например, операторы) - DONE
Конструкторы сделать explicit - TODO?
Итератор наследовать от bidirectional_tag - DONE
*/
template<typename T>
class Set: public BaseCollection {
public:
    Set() = default;
    Set(const Set<T>& set);
    Set(Set<T>&& set) noexcept;
    explicit Set(const std::initializer_list<T> elements);
    Set(const T* array, size_t length);

    ~Set() override;

    bool has(const T& value) const;
    ConstSetIterator<T> find(const T& value) const;

    size_t capacity() const;
    
    void erase(const T& value);
    void erase(const ConstSetIterator<T>& iterator);

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
    Set<T> unite(const Set<T>& set) const;
    Set<T> difference(const Set<T>& set) const;
    Set<T> symmetricDifference(const Set<T>& set)const;

    Set<T> operator&(const Set<T>& set) const;
    Set<T> operator|(const Set<T>& set) const;
    Set<T> operator+(const Set<T>& set) const;
    Set<T> operator-(const Set<T>& set) const;
    Set<T> operator^(const Set<T>& set) const;

    Set<T>& operator&=(const Set<T>& set);
    Set<T>& operator|=(const Set<T>& set);
    Set<T>& operator+=(const Set<T>& set);
    Set<T>& operator-=(const Set<T>& set);
    Set<T>& operator^=(const Set<T>& set);

    Set<T>& operator=(const Set<T> set);
    Set<T>& operator=(Set<T>&& set) noexcept;

    bool operator==(const Set<T> set) const;
    bool operator!=(const Set<T> set) const;

protected:
    bool add(const std::shared_ptr<SetNode<T>>& node);

private:
    std::shared_ptr<SetNode<T>> head;
    std::shared_ptr<SetNode<T>> tail;
};

#include "Set.hpp"
#endif