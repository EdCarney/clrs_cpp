#ifndef PRIME_NUMBERS_HPP_INCLUDED
#define PRIME_NUMBERS_HPP_INCLUDED

#include <vector>

namespace prime_numbers {

    // generates all primes up to max via sieve method
    std::vector<int> generate_primes_sieve(int max);

}
#endif // PRIME_NUMBERS_HPP_INCLUDED
