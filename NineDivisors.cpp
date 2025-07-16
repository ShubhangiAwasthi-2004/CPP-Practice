class Solution {
  public:
    int countNumbers(int n) {
        // Code Here
       vector<bool> isPrime(100000, true);
        vector<int> primes;

        isPrime[0] = isPrime[1] = false;

        // Sieve of Eratosthenes
        for (int i = 2; i * i < isPrime.size(); i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < isPrime.size(); j += i)
                    isPrime[j] = false;
            }
        }

        // Collect all primes
        for (int i = 2; i < isPrime.size(); i++) {
            if (isPrime[i])
                primes.push_back(i);
        }

        int count = 0;

        // Case 1: p^8
        for (int i = 0; i < primes.size(); i++) {
            long long val = 1;
            for (int j = 0; j < 8; j++) val *= primes[i];
            if (val <= n) count++;
            else break;
        }

        // Case 2: p^2 * q^2 (p != q)
        int sz = primes.size();
        for (int i = 0; i < sz; i++) {
            long long p2 = 1LL * primes[i] * primes[i];
            if (p2 > n) break;

            for (int j = i + 1; j < sz; j++) {
                long long q2 = 1LL * primes[j] * primes[j];
                if (p2 * q2 <= n)
                    count++;
                else
                    break;
            }
        }

        return count;
    }
    
};
