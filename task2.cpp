/// @file
/// @brief Task2: member function definitions/implementations

#include "task2.hpp" // task2::select, task2::select_union

#include <unordered_set> // std::unordered_set
#include <vector>        // std::vector

/// @todo Include additional standard library headers as needed

namespace task2 {

/// @todo Implement function 'select' as declared and specified in task2.hpp
std::unordered_set<size_t> select(const std::vector<Vec2d>& vertices, const Region& region,
                                  bool invert) {
  std::unordered_set<size_t> selected_indices;
  for (int i = 0; i < vertices.size(); ++i) {
    if (region(vertices[i]) != invert) {
      selected_indices.insert(i);
    }
  }

  return selected_indices;
}

/// @todo Implement function 'select_union' as declared and specified in task2.hpp
std::unordered_set<size_t> select_union(const std::vector<Vec2d>& vertices,
                                        const std::vector<Region>& regions, bool invert) {
  std::unordered_set<size_t> selected_indices;
  for (int i = 0; i < vertices.size(); ++i) {
    bool is_selected = false;
    for (const auto& region : regions) {
      if (region(vertices[i])) {
        is_selected = true;
        break;
      }
    }
    if (is_selected != invert) {
      selected_indices.insert(i);
    }
  }

  return selected_indices;
}
} // namespace task2
