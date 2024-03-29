#ifndef VECTOR4D_H_

#define VECTOR4D_H_

#include <cmath>

#include "containers/Vector/Vector.h"

template <typename T>
class Vector4D : public Vector<4, T> {
  static_assert(std::is_arithmetic<T>::value, "Type must be arithmetic");

 public:
  Vector4D();
  Vector4D(const T&, const T&, const T&);
  Vector4D(std::initializer_list<T>);
  Vector4D(const Vector4D&);
  Vector4D(Vector4D&&) noexcept;

  Vector4D& operator=(const Vector<4, T>&);
  Vector4D& operator=(Vector4D&&) noexcept;

  T length();
  void normalize();

  static T dot(const Vector4D&, const Vector4D&);
  static Vector4D cross(const Vector4D&, const Vector4D&);
};

#include "Vector4D.hpp"

#endif
