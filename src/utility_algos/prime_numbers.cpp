#include "prime_numbers.hpp"
#include <vector>
#include <cmath>
#include <unordered_set>

namespace prime_numbers {

    std::vector<int> generate_primes_sieve(int max) {
        if (max < 2) {
            return std::vector<int>();
        }

        int max_sqrt = std::sqrt(max);
        std::unordered_set<int> marked;
        int i = 1;
        while (++i < max_sqrt) {
            if (marked.count(i)) {
                continue;
            }
            int j = i * i;
            while (j <= max) {
                marked.insert(j);
                j += i;
            }
        }

        std::vector<int> primes(max - marked.size() - 1);
        i = 1;
        int p = 0;
        while (++i <= max) {
            if (!marked.count(i)) {
                primes[p++] = i;
            }
        }

        return primes;
    }
}
