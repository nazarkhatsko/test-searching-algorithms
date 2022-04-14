#include "tools.hpp"
#include "algorithms.hpp"

#include <thread>

double wrapper_for_thread(std::function<int(const std::vector<int> &, const int)> f, const std::vector<int> &a, const int v) {
    const auto r = execution_time([&]() {
        return f(a, v);
    });
    return r;
}

int main() {
    std::cout << std::fixed;
    std::cout << "TSA (Test Searching Algorithms)\n";
    std::cout << "Version 1.2 (threads)\n";
    std::cout << "\n";

    const auto size = std::stoi(input("Enter size: "));
    const auto value = std::stoi(input("Enter value: "));
    const auto array = generate_array(size);

    auto result = result_t({
        {"linear search",        0.0},
        {"binary search",        0.0},
        {"jump search",          0.0},
        {"interpolation search", 0.0},
        {"exponential search",   0.0},
        {"fibonacci search",     0.0}
    });

    const auto total_time = execution_time([&]() {
        auto threads = std::vector<std::thread>(6);
        threads[0] = std::thread([&]() { result[0].second = wrapper_for_thread(linear_search, array, value); });
        threads[1] = std::thread([&]() { result[1].second = wrapper_for_thread(binary_search, array, value); });
        threads[2] = std::thread([&]() { result[2].second = wrapper_for_thread(jump_search, array, value); });
        threads[3] = std::thread([&]() { result[3].second = wrapper_for_thread(interpolation_search, array, value); });
        threads[4] = std::thread([&]() { result[4].second = wrapper_for_thread(exponential_search, array, value); });
        threads[5] = std::thread([&]() { result[5].second = wrapper_for_thread(fibonacci_search, array, value); });

        for (auto &i : threads) {
            if (i.joinable()) {
                i.join();
            }
        }
        return 0;
    });
    
    sort_result(result);
    print_result(result);

    std::cout << "Total time: " << total_time << " seconds\n";

    return EXIT_SUCCESS;
}
