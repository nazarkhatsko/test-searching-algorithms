#include "tools.hpp"
#include "algorithms.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <thread>
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


void wrapper_for_thread(std::function<double()> f, double &r) {

	r = f();

};


int main() {

	std::cout << std::fixed;

	std::cout << "TSA (Test Searching Algorithms)" << '\n';
	std::cout << "Version 1.1 (thread)" << '\n';
	std::cout << '\n';

	auto size = std::stoi(input("enter size: "));
	auto value = std::stoi(input("enter value: "));
	auto array = generate_array(size);

	auto result = std::vector<pair_t>({
		{"linear search", 0.0},
		{"binary search", 0.0},
		{"jump search", 0.0},
		{"interpolation search", 0.0},
		{"exponential search", 0.0},
		{"fibonacci search", 0.0}
	});

	auto start = std::chrono::steady_clock::now();

	auto threads = std::vector<std::thread>(6);

	threads.at(0) = std::thread(wrapper_for_thread, std::bind(test_algorithm, [&]() {
		return linear_search(array, value);
	}), std::ref(result.at(0).second));

	threads.at(1) = std::thread(wrapper_for_thread, std::bind(test_algorithm, [&]() {
		return binary_search(array, value);
	}), std::ref(result.at(1).second));

	threads.at(2) = std::thread(wrapper_for_thread, std::bind(test_algorithm, [&]() {
		return jump_search(array, value);
	}), std::ref(result.at(2).second));

	threads.at(3) = std::thread(wrapper_for_thread, std::bind(test_algorithm, [&]() {
		return interpolation_search(array, value);
	}), std::ref(result.at(3).second));

	threads.at(4) = std::thread(wrapper_for_thread, std::bind(test_algorithm, [&]() {
		return exponential_search(array, value);
	}), std::ref(result.at(4).second));

	threads.at(5) = std::thread(wrapper_for_thread, std::bind(test_algorithm, [&]() {
		return fibonacci_search(array, value);
	}), std::ref(result.at(5).second));

	for (auto &i : threads) {
		if (i.joinable()) {
			i.join();
		};
	};

	auto end = std::chrono::steady_clock::now();

	std::sort(result.begin(), result.end(), [](const pair_t &a, const pair_t &b) -> bool {
		return a.second < b.second;
	});
	print_result(result);

	std::cout << "total time: " << std::chrono::duration<double>(end - start).count() << '\n';

	return 0;

};
