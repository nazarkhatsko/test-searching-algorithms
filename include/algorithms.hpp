#pragma once

#include <vector>
#include <cmath>

int linear_search        (const std::vector<int> &v, const int x);
int binary_search        (const std::vector<int> &v, const int x);
int jump_search          (const std::vector<int> &v, const int x);
int interpolation_search (const std::vector<int> &v, const int x);
int exponential_search   (const std::vector<int> &v, const int x);
int fibonacci_search     (const std::vector<int> &v, const int x);
