/// @file
/// @brief Task3: tests

#include "task3.hpp" // task3::generate_double_annulus

#include "iue-msh/triangles.hpp" // iue::msh::Triangles

#include <cassert>    // assert
#include <filesystem> // std::filesystem::exists
#include <iostream>   // std::cout, sts::endl
#include <string>     // std::string

int main() {

  using namespace task2;

  std::string filepath = "task3.test.svg";

  task2::Vec2d c1 = {5, 5};
  task2::Vec2d c2 = {10, 10};
  double r = 3;
  double R = 4;
  double h = 0.15;
  auto mesh = task3::generate_double_annulus(c1, c2, r, R, h);
  std::filesystem::remove(filepath);
  mesh.save(filepath);
  assert(std::filesystem::exists(filepath));
  auto bbox = mesh.bbox();
  auto [bbmin, bbmax] = bbox;
  assert(bbmin[0] <= c1[0] - R + 2 * h);
  assert(bbmax[0] >= c2[0] + R - 2 * h);
  assert(bbmin[1] <= c1[1] - R + 2 * h);
  assert(bbmax[1] >= c2[1] + R - 2 * h);

  std::cout << "task3.test.cpp: all asserts passed" << std::endl;

  return 0;
}
