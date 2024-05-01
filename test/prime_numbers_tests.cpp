#include "../src/utility_algos/prime_numbers.hpp"
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

TEST(PrimeNumbersSieveTests, ZeroMax) {
    std::vector primes = prime_numbers::generate_primes_sieve(0);
    
    EXPECT_EQ(primes.size(), 0);
}

TEST(PrimeNumbersSieveTests, NonZeroLowMax) {
    std::vector primes = prime_numbers::generate_primes_sieve(2);
    std::vector expected { 2 };
    
    EXPECT_EQ(primes.size(), expected.size());

    for (int &e : expected) {
        EXPECT_NE(std::find(primes.begin(), primes.end(), e), primes.end()) << "Did not find prime: " << e;
    }
}

TEST(PrimeNumbersSieveTests, NonZeroMax) {
    std::vector primes = prime_numbers::generate_primes_sieve(100);
    std::vector expected { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
    
    EXPECT_EQ(primes.size(), expected.size());

    for (int &e : expected) {
        EXPECT_NE(std::find(primes.begin(), primes.end(), e), primes.end()) << "Did not find prime: " << e;
    }
}
