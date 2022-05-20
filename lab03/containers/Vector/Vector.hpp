#include <experimental/iterator>

template <std::size_t Size, typename T>
constexpr Vector<Size, T>::Vector() noexcept : data{} {}

template <std::size_t Size, typename T>
constexpr Vector<Size, T>::Vector(const valueType& value) noexcept : data{} {
  fill(value);
}

template <std::size_t Size, typename T>
constexpr Vector<Size, T>::Vector(std::initializer_list<valueType> list) noexcept : data{} {
  auto i = begin();
  for (auto j = list.begin(); i != end() && j != list.end(); ++i, ++j)
    *i = *j;
}

template <std::size_t Size, typename T> template <std::size_t OtherSize, typename U>
constexpr Vector<Size, T>::Vector(const Vector<OtherSize, U>& other) noexcept : data{} {
  for (std::size_t i = 0; i != min(size(), other.size()); ++i)
    data[i] = other[i];
}

template <std::size_t Size, typename T>
constexpr void Vector<Size, T>::fill(const valueType& value) {
  for (std::size_t i = 0; i != size(); ++i)
    data[i] = value;
}

template <std::size_t Size, typename T>
constexpr auto Vector<Size, T>::begin() -> iterator {
  return iterator(std::addressof(data[0]));
}

template <std::size_t Size, typename T>
constexpr auto Vector<Size, T>::begin() const -> constIterator {
  return constIterator(std::addressof(data[0]));
}

template <std::size_t Size, typename T>
constexpr auto Vector<Size, T>::end() -> iterator {
  return iterator(std::addressof(data[Size]));
}

template <std::size_t Size, typename T>
constexpr auto Vector<Size, T>::end() const -> constIterator {
  return constIterator(std::addressof(data[Size]));
}

template <std::size_t Size, typename T>
constexpr auto Vector<Size, T>::size() const -> sizeType {
  return Size;
}

template <std::size_t Size, typename T>
constexpr auto Vector<Size, T>::operator[](sizeType index) -> reference {
  return data[index];
}

template <std::size_t Size, typename T>
constexpr auto Vector<Size, T>::operator[](sizeType index) const -> constReference {
  return data[index];
}

template <std::size_t Size, typename T>
auto Vector<Size, T>::at(sizeType index) -> reference {
  if (index >= size())
    throw std::out_of_range("Vector::at");
  return data[index];
}

template <std::size_t Size, typename T>
auto Vector<Size, T>::at(sizeType index) const -> constReference {
  if (index >= size())
    throw std::out_of_range("Vector::at");
  return data[index];
}

template <std::size_t Size, typename T>
std::istream& operator>>(std::istream& is, Vector<Size, T>& vector) {
  for (auto& it: vector)
    is >> it;
  return is;
}

template <std::size_t Size, typename T>
std::ostream& operator<<(std::ostream& os, const Vector<Size, T>& vector) {
  std::copy(vector.begin(), vector.end(), std::experimental::make_ostream_joiner(os, " "));
  return os;
}
