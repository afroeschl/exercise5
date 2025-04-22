/// @file
/// @brief Task1: "single-file" excutable C++ program

/// @todo Include standard library headers as needed
#include <iostream>
#include <unordered_set>
#include <vector>

namespace task1 {

/// @todo Implement a function 'count_unique' according to the description below:
/// - a sequence of integer values is received via a parameter of type std::vector<int>
/// - the function finds the unique entries in the sequence by inserting each value into a
/// std::unordered_set<int>
/// - the values in a std::unordered_set are unique, so the number of unique entries is the size of
/// the set
/// - the function then returns the number of unique entries

} // namespace task1

/// @todo Implement a main funtion conducting the following tasks in this order:
/// - fill a std::vector<int> with with this sequence of values
///   1,1,10,2,2,3,4,5,6,7,8,9,10,3,3,11,12,13,14
/// - use your function to count the unique values in the sequence above
/// - print the number of unique values to the console

int count(std::vector<int> values) {
  std::unordered_set<int> unique_values;
  for (int value : values) {
    unique_values.insert(value);
  }
  return unique_values.size();
}

int main() {
  std::vector<int> values = {1, 1, 10, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10, 3, 3, 11, 12, 13, 14};
  std::cout << count(values) << std::endl;
  return 0;
}
