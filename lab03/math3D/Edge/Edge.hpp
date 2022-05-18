constexpr Edge::Edge(std::size_t p1, std::size_t p2)
    : p1_(p1), p2_(p2) {}

constexpr auto Edge::p1() -> reference {
  return p1_;
}

constexpr auto Edge::p1() const -> constReference {
  return p1_;
}

constexpr auto Edge::p2() -> reference {
  return p2_;
}

constexpr auto Edge::p2() const -> constReference {
  return p2_;
}

constexpr auto Edge::operator[](sizeType index) -> reference {
  return *(&p1_ + index);
}

constexpr auto Edge::operator[](sizeType index) const -> constReference {
  return *(&p1_ + index);
}

inline auto Edge::at(sizeType index) -> reference {
  if (index >= 2)
    throw std::out_of_range("Edge::at");
  return *(&p1_ + index);
}

inline auto Edge::at(sizeType index) const -> constReference {
  if (index >= 2)
    throw std::out_of_range("Edge::at");
  return *(&p1_ + index);
}

inline std::istream& operator>>(std::istream& is, Edge& edge) {
  return is >> edge.p1() >> edge.p2();
}

inline std::ostream& operator<<(std::ostream& os, const Edge& edge) {
  return os << edge.p1() << ' ' << edge.p2();
}
