#pragma once

#include <vector>
#include <cmath>


using data_t = int;


int linear_search(const std::vector<data_t> &, data_t);

int binary_search(const std::vector<data_t> &, data_t);

int jump_search(const std::vector<data_t> &, data_t);

int interpolation_search(const std::vector<data_t> &, data_t);

int exponential_search(const std::vector<data_t> &, data_t);

int fibonacci_search(const std::vector<data_t> &, data_t);
