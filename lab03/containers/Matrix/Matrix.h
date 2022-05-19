#ifndef MATRIX_H_
#define MATRIX_H_

#include "containers/RectangularMatrix/RectangularMatrix.h"

template <std::size_t size, typename T>
class Matrix : public RectangularMatrix<size, size, T> {
 public:
  using Base = RectangularMatrix<size, size, T>;
  using valueType = typename Base::valueType;
  using reference = typename Base::reference;
  using constReference = typename Base::constReference;

  using iterator = typename Base::iterator;
  using constIterator = typename Base::constIterator;
  using sizeType = typename Base::sizeType;

 public:
  constexpr static Matrix Identity();

  constexpr Matrix() noexcept = default;
  constexpr explicit Matrix(T value) noexcept;
  constexpr Matrix(std::initializer_list<Vector<size, T>> list) noexcept;
};

#include "Matrix.hpp"

#endif  
