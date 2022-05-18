#ifndef EDGE_H_
#define EDGE_H_

#include <istream>
#include <ostream>

class Edge {
 public:
  using reference = std::size_t&;
  using constReference = const std::size_t&;
  using sizeType = std::size_t;

  constexpr explicit Edge(std::size_t p1 = 0, std::size_t p2 = 0);

  constexpr reference p1();
  constexpr constReference p1() const;
  constexpr reference p2();
  constexpr constReference p2() const;

  constexpr reference operator[](sizeType index);
  constexpr constReference operator[](sizeType index) const;
  inline reference at(sizeType index);
  inline constReference at(sizeType index) const;

 private:
  std::size_t p1_, p2_;
};

inline std::istream& operator>>(std::istream& is, Edge& edge);
inline std::ostream& operator<<(std::ostream& os, const Edge& edge);

#include "Edge.hpp"

#endif  // LAB04_MATH3D_EDGE_HPP_