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

	int l = 0;
	int r = v.size() - 1;

	while (l <= r) {
		int n = l + (r - l) / 2;
		if (v.at(n) == x) {
			return n;
		} else if (v.at(n) < x) {
			l = n + 1;
		} else {
			r = n - 1;
		};
	};

	return -1;

};


int jump_search(const std::vector<data_t> &v, data_t x) {

	int prev = 0;
	int step = std::sqrt(v.size());

	while (v.at(std::fmin(step, v.size()) - 1) < x) {
		prev = step;
		step += std::sqrt(v.size());
		if (prev >= v.size()) {
			return -1;
		};
	};

	while (v.at(prev) < x) {
		prev++;

		if (prev == std::fmin(step, v.size())) {
			return -1;
		};
	};

	if (v.at(prev) == x) {
		return prev;
	};

	return -1;

};


int interpolation_search(const std::vector<data_t> &v, data_t x) {

	int l = 0;
	int r = v.size() - 1;

	if (l <= r && x >= v.at(l) && x <= v.at(r)) {
		int i = l + ((static_cast<double>(r - l) / (v.at(r) - v.at(l))) * (x - v.at(l)));

		if (v.at(i) == x) {
			return i;
		} else if (v.at(i) < x) {
			l = i + 1;
		} else {
			r = i - 1;
		};
	};

	return -1;

};


int exponential_search(const std::vector<data_t> &v, data_t x) {

	if (v.front() == x) {
		return 0;
	};

	int i = 1;
	while (i < v.size() && v.at(i) <= x) {
		i = i * 2;
	};

	int l = i / 2;
	int r = std::fmin(i, v.size() - 1);

	while (l <= r) {
		int n = l + (r - l) / 2;
		if (v.at(n) == x) {
			return n;
		} else if (v.at(n) < x) {
			l = n + 1;
		} else {
			r = n - 1;
		};
	};

	return -1;

};


int fibonacci_search(const std::vector<data_t> &v, data_t x) {

	int fib_num_1 = 1;
	int fib_num_2 = 0;
	int fib_sum = fib_num_2 + fib_num_1;

	while (fib_sum < v.size()) {
		fib_num_2 = fib_num_1;
		fib_num_1 = fib_sum;
		fib_sum = fib_num_2 + fib_num_1;
	};

	int offset = -1;
	while (fib_sum > 1) {
		int i = std::fmin(offset + fib_num_2, v.size() - 1);

		if (v.at(i) < x) {
			fib_sum = fib_num_1;
			fib_num_1 = fib_num_2;
			fib_num_2 = fib_sum - fib_num_1;
			offset = i;
		} else if (v.at(i) > x) {
			fib_sum = fib_num_2;
			fib_num_1 = fib_num_1 - fib_num_2;
			fib_num_2 = fib_sum - fib_num_1;
		} else {
			return i;
		};
	};

	return -1;

};
