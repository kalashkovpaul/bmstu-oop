#ifndef VECTOR_H_
#define VECTOR_H_

#include <initializer_list>
#include <istream>
#include <ostream>

template <std::size_t Size, typename T>
class Vector {
 public:
  using valueType = T;
  using reference = T&;
  using constReference = const T&;

  using iterator = valueType*;
  using constIterator = const valueType*;
  using sizeType = std::size_t;

 public:
  constexpr Vector() noexcept;
  constexpr explicit Vector(const valueType& value) noexcept;
  constexpr Vector(std::initializer_list<valueType> list) noexcept;
  template <std::size_t OtherSize, typename U>
  constexpr explicit Vector(const Vector<OtherSize, U>& other) noexcept;

  constexpr void fill(const valueType& value);

  constexpr iterator begin();
  constexpr constIterator begin() const;
  constexpr iterator end();
  constexpr constIterator end() const;

  constexpr sizeType size() const;

  constexpr reference operator[](sizeType index);
  constexpr constReference operator[](sizeType index) const;
  reference at(sizeType index);
  constReference at(sizeType index) const;

 protected:
  T data[Size ? Size : 1];
};

template <std::size_t Size, typename T>
std::istream& operator>>(std::istream& is, Vector<Size, T>& vector);
template <std::size_t Size, typename T>
std::ostream& operator<<(std::ostream& os, const Vector<Size, T>& vector);

#include "Vector.hpp"

#endif
