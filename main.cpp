#include "tools.hpp"
#include "algorithms.hpp"

int main() {
    std::cout << std::fixed;
    std::cout << "TSA (Test Searching Algorithms)\n";
    std::cout << "Version 1.2\n";
    std::cout << "\n";

    const auto size  = std::stoi(input("Enter size: "));
    const auto value = std::stoi(input("Enter value: "));
    const auto array = generate_array(size);

    const auto total_time = execution_time([&]() {
        auto result = result_t({
            {"linear search",        execution_time(std::bind(linear_search, array, value))},
            {"binary search",        execution_time(std::bind(binary_search, array, value))},
            {"jump search",          execution_time(std::bind(jump_search, array, value))},
            {"interpolation search", execution_time(std::bind(interpolation_search, array, value))},
            {"exponential search",   execution_time(std::bind(exponential_search, array, value))},
            {"fibonacci search",     execution_time(std::bind(fibonacci_search, array, value))}
        });
        sort_result(result);
        print_result(result);
        return 0;
    });

    std::cout << "Total time: " << total_time << " seconds\n";

    return EXIT_SUCCESS;
}
