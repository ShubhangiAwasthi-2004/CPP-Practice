You are given an array arr[] of positive integers. Your task is to count the number of pairs (i, j) such that:


0 ≤ i < j ≤ n-1
gcd(arr[i], arr[j]) = 1
In other words, count the number of unordered pairs of indices (i, j) where the elements at those positions are co-prime.

Examples:

Input: arr[] = [1, 2, 3]
Output: 3
Explanation: (0,1), (0,2), (1,2) are the pair of indices where gcd(arr[i], arr[j]) = 1
Input: arr[] = [4, 8, 3, 9]
Output: 4
Explanation: (0,2), (0,3), (1,2), (1,3) are the pair of indices where gcd(arr[i], arr[j]) = 1
Constraints:
2 ≤ arr.size() ≤ 104
1 ≤ arr[i] ≤ 104


class Solution {
  public:
    int cntCoprime(vector<int>& arr) {
        // code here
        const int MAX = 10000;
        int n = arr.size();
        vector<int> freq(MAX + 1, 0);
        
        for (int num : arr)
            freq[num]++;

        // Count multiples of every number using sieve
        vector<int> multiples(MAX + 1, 0);
        for (int i = 1; i <= MAX; ++i) {
            for (int j = i; j <= MAX; j += i) {
                multiples[i] += freq[j];
            }
        }

        // Total number of pairs (i < j)
        long long totalPairs = 1LL * n * (n - 1) / 2;

        // Mobius function for inclusion-exclusion
        vector<int> mobius(MAX + 1, 1);
        vector<bool> isPrime(MAX + 1, true);
        for (int i = 2; i <= MAX; ++i) {
            if (isPrime[i]) {
                for (int j = i; j <= MAX; j += i) {
                    isPrime[j] = false;
                    mobius[j] *= -1;
                }
                long long sq = 1LL * i * i;
                for (int j = sq; j <= MAX; j += sq)
                    mobius[j] = 0;  // Not square-free
            }
        }

        // Count non-coprime pairs using inclusion-exclusion
        long long nonCoprimePairs = 0;
        for (int d = 2; d <= MAX; ++d) {
            if (mobius[d] == 0) continue;
            long long cnt = multiples[d];
            if (cnt < 2) continue;
            long long pairs = cnt * (cnt - 1) / 2;
            nonCoprimePairs += pairs * -mobius[d];
        }

        return (int)(totalPairs - nonCoprimePairs);
    }
};
