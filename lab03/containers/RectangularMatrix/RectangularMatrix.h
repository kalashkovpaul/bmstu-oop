#ifndef RECTANGULAR_MATRIX_H_

#define RECTANGULAR_MATRIX_H_

#include "containers/Vector/Vector.h"

template <std::size_t rows, std::size_t cols, typename T>
class RectangularMatrix {
 public:
  using valueType = Vector<cols, T>;
  using reference = Vector<cols, T> &;
  using constReference = const Vector<cols, T> &;

  using iterator = valueType *;
  using constIterator = const valueType *;
  using sizeType = std::size_t;

 public:
  constexpr RectangularMatrix() = default;
  constexpr explicit RectangularMatrix(T value) noexcept;
  constexpr RectangularMatrix(std::initializer_list<Vector <cols, T>> list) noexcept;

  constexpr iterator begin();
  constexpr constIterator begin() const;
  constexpr iterator end();
  constexpr constIterator end() const;

  constexpr reference operator[](sizeType index);
  constexpr constReference operator[](sizeType index) const;
  reference at(sizeType index);
  constReference at(sizeType index) const;

 protected:
  Vector<rows, Vector<cols, T>> data_;
};

template <std::size_t rows, std::size_t cols, typename T>
std::istream& operator<<(std::istream& is, RectangularMatrix<rows, cols, T>& matrix);
template <std::size_t rows, std::size_t cols, typename T>
std::ostream& operator<<(std::ostream& os, const RectangularMatrix<rows, cols, T>& matrix);

template <std::size_t L, std::size_t M, std::size_t N, typename T>
const RectangularMatrix<L, N, T> operator*(const RectangularMatrix<L, M, T>& m1, const RectangularMatrix<M, N, T>& m2);

#include "RectangularMatrix.hpp"

#endif 
