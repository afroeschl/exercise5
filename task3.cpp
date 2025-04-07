/// @file
/// @brief Task3: implementation

#include "task3.hpp" // task3::generate_double_annulus
#include "task2.hpp" // task2::select, task2::select_union

#include "iue-msh/triangles.hpp" // iue::msh::Triangles

/// @todo Include additional standard library headers as needed

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

  /// @note this is just dummy content, adapt as needed
  task2::Vec2d min = {0, 0};
  task2::Vec2d max = {10, 10};
  auto mesh = iue::msh::Triangles({min, max}, h);
  return mesh;
}

} // namespace task3
