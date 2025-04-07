/// @file
/// @brief Task2: tests

#include "task2.hpp" // task2::select, task2::select_union

#include "iue-rnd/random.hpp" // iue::rnd::UniformValue

#include <algorithm> // std::sort
#include <array>     // std::array
#include <cassert>   // assert
#include <cmath>     // std::sqrt
#include <iostream>  // std::cout, std::endl
#include <numbers>   // std::numbers::pi

int main() {

  using namespace task2;

  std::vector<Vec2d> vertices;

  // upper diagonal halfspace region
  auto upper_diagonal_halfspace = [](const Vec2d& coord) -> bool {
    auto [x, y] = coord;
    if (y > x && std::abs(x - y) > 1e-9)
      return true;
    return false;
  };

  { // adding random vertices in upper diagonal halfspace
    auto gen = iue::rnd::UniformValue(-1.0, 1.0);
    for (int n = 0; n != 1e2; ++n) {
      std::array<double, 2> xy{gen(), gen()};
      std::ranges::sort(xy);
      vertices.push_back({xy});
    }
  }

  // testing task::select

  {
    auto subset = task2::select(vertices, upper_diagonal_halfspace, false);
    assert(subset.size() == vertices.size());
  }

  {
    auto subset = task2::select(vertices, upper_diagonal_halfspace, true);
    assert(subset.size() == 0);
  }

  // testing task::select_union

  // circular region around center(1,1) with radius 1
  Circle circle = {{1, 1}, 1};
  auto circle_c11_r1 = [&circle](const Vec2d& coord) -> bool {
    auto [c, r] = circle;
    auto [cx, cy] = c;
    auto [x, y] = coord;
    return std::sqrt((x - cx) * (x - cx) + (y - cy) * (y - cy)) < r ? true : false;
  };

  { // adding random vertices inside the circle
    auto [center, r] = circle;
    auto gen_angle = iue::rnd::UniformValue(0, std::numbers::pi * 2);
    auto gen_radius = iue::rnd::UniformValue(0, r - 1e-9);
    for (int n = 0; n != 1e3; ++n) {
      double angle = gen_angle();
      double radius = gen_radius();
      std::array<double, 2> xy{center[0] + std::cos(angle) * radius, center[1] + std::sin(angle) * radius};
      vertices.push_back({xy});
    }
  }

  {
    auto subset = task2::select_union(vertices, {upper_diagonal_halfspace, circle_c11_r1}, false);
    assert(subset.size() == vertices.size());
  }

  {
    auto subset = task2::select_union(vertices, {upper_diagonal_halfspace, circle_c11_r1}, true);
    assert(subset.size() == 0);
  }

  std::cout << "task2.test.cpp: all asserts passed" << std::endl;

  return 0;
}
