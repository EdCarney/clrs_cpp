#include "prime_numbers.hpp"
#include <vector>

int main() {
    std::vector<int> primes = prime_numbers::generate_primes_sieve(2);
}
