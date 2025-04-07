/// @file
/// @brief Task2: class definitions with member function declarations

#pragma once

#include <array>         // std::array
#include <functional>    // std::function
#include <unordered_set> // std::unordered_set
#include <vector>        // std::vector

namespace task2 {

/// @brief two-dimensional coordinate
using Vec2d = std::array<double, 2>;

/// @brief Circle with center and radius
using Circle = std::tuple<Vec2d, double>;

/// @brief Axis-aligned bounding box with bottom left and top right coordinate)
using BBox = std::tuple<Vec2d, Vec2d>;

/// @brief Arbitrary two-dimensional region described by a boolean function returning
/// - true, if the point/coordinate in question lies inside this region, and
/// - false, otherwise.
using Region = std::function<bool(Vec2d)>;

/// @brief Selects the subset of vertices for which a boolean function evaluates to true
/// @param vertices Two-dimensional vertices to select from
/// @param region Boolean function to evaluate if a vertex is selected
/// @param invert Inverts the selection process if set to true
/// @return Indices of the selected vertices 
std::unordered_set<size_t> select(const std::vector<Vec2d>& vertices, const Region& region, bool invert = false);

/// @brief Selects the subset of vertices for which ANY of a sequence of boolean functions evaluates to true
/// @param vertices Two-dimensional vertices to select from
/// @param regions Sequence of boolean functions to evaluate
/// @param invert Performs an inversion of the final selection if set to 'true'
/// @return Indices of the selected vertices
std::unordered_set<size_t> select_union(const std::vector<Vec2d>& vertices, const std::vector<Region>& regions,
                                        bool invert = false);

} // namespace task2
