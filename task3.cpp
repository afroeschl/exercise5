/// @file
/// @brief Task3: implementation

#include "task3.hpp" // task3::generate_double_annulus
#include "task2.hpp" // task2::select, task2::select_union

#include "iue-msh/triangles.hpp" // iue::msh::Triangles

/// @todo Include additional standard library headers as needed
#include <cmath> // std::exp

namespace task3 {

using namespace task2;

/// @todo Implement function 'generate_double_annulus' as declared and specified in task3.hpp
/// Implementation Hints:
///   - calculate the required bounding box for the annuluses using the centers coordinates +- outer
///   radius
///   - create a triangle mesh using the desired bounding box and resolution (h)
///   - use the source code of task2.test.cpp for ideas how to create the boolean functions for
///   circular regions
///   - select the union of the two inner circles and remove the triangles using the following
///   functions:
///      - mesh.getVertices()
///      - task2::select_union(...)
///      - mesh.remove_vertices(...)
///   - analoguously, select the union of the two outer circles and remove the INVERSE of this union
///   using
///      - mesh.getVertices()
///      - task2::select_union(..., true)
///      - mesh.remove_vertices(...)

iue::msh::Triangles generate_double_annulus(task2::Vec2d c1, task2::Vec2d c2, double r, double R,
                                            double h) {

  double min_x = std::min(c1[0] - R, c2[0] - R);
  double min_y = std::min(c1[1] - R, c2[1] - R);
  double max_x = std::max(c1[0] + R, c2[0] + R);
  double max_y = std::max(c1[1] + R, c2[1] + R);

  // Adding padding
  min_x -= 2 * h;
  min_y -= 2 * h;
  max_x += 2 * h;
  max_y += 2 * h;

  task2::Vec2d min = {min_x, min_y};
  task2::Vec2d max = {max_x, max_y};

  auto mesh = iue::msh::Triangles({min, max}, h);

  auto isOuterR = [R](const Vec2d& c) {
    return [R, c](const Vec2d& v) {
      // Compute the squared distance from the center c
      return (pow(v[0] - c[0], 2) + pow(v[1] - c[1], 2)) < R * R;
    };
  };

  auto isInnerR = [r](const Vec2d& c) {
    return [r, c](const Vec2d& v) {
      // Compute the squared distance from the center c
      return (pow(v[0] - c[0], 2) + pow(v[1] - c[1], 2)) > r * r;
    };
  };

  std::vector<Region> regions = {isOuterR(c1), isOuterR(c2), isInnerR(c1), isInnerR(c2)};
  std::vector<Vec2d> vertices = mesh.getVertices();

  std::unordered_set<size_t> removeSet = select_union(vertices, regions, 1);
  mesh.remove_vertices(removeSet);

  return mesh;
}

} // namespace task3
