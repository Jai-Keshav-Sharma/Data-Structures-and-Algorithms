//leetcode- 204

class Solution {
public:
    /**
     * @brief Counts the number of prime numbers less than a given number n.
     * 
     * This function uses the Sieve of Eratosthenes algorithm to count the number of prime numbers
     * less than the input integer n. It initializes a boolean vector to keep track of prime numbers
     * and iteratively marks the multiples of each prime number as non-prime.
     * 
     * @param n The upper limit (exclusive) for counting prime numbers.
     * @return int The count of prime numbers less than n.
     */
    int countPrimes(int n) {
        int count = 0;
        vector<bool> is_prime(n + 1, true);

        is_prime[0] = is_prime[1] = false;

        for(long long int i = 2; i < n; i++)
        {
            if(is_prime[i])
            {   
                count++;
                for(long long int j = i * i; j < n; j = j + i)
                {
                    is_prime[j] = false;
                }
            }
        }
        return count;
    }
};