/// @file
/// @brief Task3: function declarations

#pragma once

#include "task2.hpp" // task2::Vec2d

#include "iue-msh/triangles.hpp" // iue::msh::Triangles

namespace task3 {

/// @brief Generates a triangle mesh placed of two (potentially merged) annuluses (Kreisringe)
/// @param c1 Center coordinate of the first annulus
/// @param c2 Center coordinate of the second annulus
/// @param r inner radius of both annuluses
/// @param R outer radius of both annuluses
/// @param h lower bound for the triangle egde length of the resulting mesh
/// @return Resulting triangle mesh 
iue::msh::Triangles generate_double_annulus(task2::Vec2d c1, task2::Vec2d c2, double r, double R, double h);

} // namespace task3
