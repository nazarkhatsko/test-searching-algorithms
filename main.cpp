#include "tools.hpp"
#include "algorithms.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <chrono>
#include <algorithm>
#include <functional>


std::vector<data_t> generate_array(std::size_t size) {

	std::vector<data_t> v(size);
	data_t el = 1;
	std::generate(v.begin(), v.end(), [&]() mutable {
		return el++; 
	});
	return v;

};


int main() {

	std::cout << std::fixed;

	std::cout << "TSA (Test Searching Algorithms)" << '\n';
	std::cout << "Version 1.1" << '\n';
	std::cout << '\n';

	auto size = std::stoi(input("enter size: "));
	auto value = std::stoi(input("enter value: "));
	auto array = generate_array(size);

	auto start = std::chrono::steady_clock::now();
	auto result = std::vector<pair_t>({
		{"linear search", test_algorithm(std::bind(linear_search, array, value))},
		{"binary search", test_algorithm(std::bind(binary_search, array, value))},
		{"jump search", test_algorithm(std::bind(jump_search, array, value))},
		{"interpolation search", test_algorithm(std::bind(interpolation_search, array, value))},
		{"exponential search", test_algorithm(std::bind(exponential_search, array, value))},
		{"fibonacci search", test_algorithm(std::bind(fibonacci_search, array, value))}
	});
	auto end = std::chrono::steady_clock::now();

	std::sort(result.begin(), result.end(), [](const pair_t &a, const pair_t &b) {
		return a.second < b.second;
	});
	print_result(result);

	std::cout << "total time: " << std::chrono::duration<double>(end - start).count() << '\n';

	return 0;

};
