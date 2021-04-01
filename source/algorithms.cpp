#include "algorithms.hpp"


int linear_search(const std::vector<data_t> &v, data_t x) {

	for (int i = 0; i < v.size(); i++) {
		if (v.at(i) == x) {
			return i;
		};
	};
	return -1;

};


int binary_search(const std::vector<data_t> &v, data_t x) {

	return -1;

};


int jump_search(const std::vector<data_t> &v, data_t x) {

	return -1;

};


int interpolation_search(const std::vector<data_t> &arr, data_t val) {

	return -1;

};


int exponential_search(const std::vector<data_t> &arr, data_t val) {

	return -1;

};


int fibonacci_search(const std::vector<data_t> &arr, data_t val) {

	return -1;

};
