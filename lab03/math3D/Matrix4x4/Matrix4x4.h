#ifndef MATRIX4X4_H_

#define MATRIX4X4_H_

#include "containers/Matrix/Matrix.h"
#include "math3D/Vector4D/Vector4D.h"
#include "math3D/Point3D/Point3D.h"

template <typename T>
class Matrix4x4 : public Matrix<4, T> {
  static_assert(std::is_arithmetic<T>::value, "Type must be arithmetic!");

 public:
  Matrix4x4();
  Matrix4x4(std::initializer_list<Vector<4, T>>);
  Matrix4x4(const Matrix4x4&);
  Matrix4x4(Matrix4x4&&) noexcept;
  ~Matrix4x4() = default;

  Matrix4x4& operator=(const Matrix4x4&);
  Matrix4x4& operator=(Matrix4x4&&) noexcept;
  Matrix4x4& operator=(std::initializer_list<Vector<4, T>>);

  Vector4D<T> operator*(const Vector4D<T>&) const;
  Matrix4x4 operator*(const T&) const;
  Point3D<T> operator*(const Point3D<T>&) const;

  template <typename U>
  friend Vector4D<U> operator*(const Vector4D<U>&, const Matrix4x4<U>&);
};

#include "Matrix4x4.hpp"

#endif
