#include "tools.hpp"

std::string input(const std::string &s) {
    std::cout << s;
    std::string r;
    std::cin >> r;
    return r;
}

double execution_time(std::function<int()> f) {
    auto start = std::chrono::steady_clock::now();
    int res = f();
    if (res != -1) {
        // item with index found res
    }
    auto end = std::chrono::steady_clock::now();
    return std::chrono::duration<double>(end - start).count();
}

void sort_result(result_t &r) {
    std::sort(r.begin(), r.end(), [](const std::pair<std::string, double> &a, const std::pair<std::string, double> &b) {
        return a.second < b.second;
    });
}

void print_result(const result_t &r) {
    std::cout << "\n";
    std::cout << "COUNT\tNAME\t\t\tTIME\n";
    std::size_t count = 1;
    for (const auto &i : r) {
        std::cout << count++ << "\t" << i.first << "\t";
        if (i.first.length() < 15) {
            std::cout << "\t";
        }
        std::cout << i.second << "s\n";
    }
    std::cout << "\n";
}

std::vector<int> generate_array(std::size_t size) {
    auto v = std::vector<int>(size);
    int el = 1;
    std::generate(v.begin(), v.end(), [&]() mutable {
        return el++; 
    });
    return v;
}
