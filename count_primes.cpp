//
// Created by David Mrnustik on 8/4/22.
//

#include <numbers>
#include <iostream>
#include <ctime>
#include <chrono>
#define MAX_PRIME 131071

uint64_t count_primes(uint64_t end) {
    constexpr auto isprime = [](const uint64_t n) {
        for(uint64_t i{2}; i < n / 2; i++) {
            if (n % i == 0) return false;
        }
        return true;
    };
    uint64_t count{0};
    uint64_t start{2};
//    uint64_t end{MAX_PRIME};
    for(uint64_t i{start}; i <= end; ++i) {
        if (isprime(i)) ++count;
    }
    return count;
};

int main() {
    time_t start = time(nullptr);
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    std::cout << std::asctime(std::localtime(&start)) << std::endl;
    std::cout << count_primes(MAX_PRIME) << " prime numbers" << std::endl;
    time_t end = time(nullptr);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    std::cout << std::asctime(std::localtime(&end)) << std::endl;

    std::chrono::duration<double, std::milli> time_span = t2 - t1;
    std::cout << "Duration in s: " << time_span.count() / 1000 << std::endl;

    return 0;
}