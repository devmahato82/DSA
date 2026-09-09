class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long start = 1000; // 10^3
        for (long long commas = 1; start <= n; commas++) {
            long long end = start * 1000 - 1;
            ans += (min(n, end) - start + 1) * commas;
            start *= 1000;
        }
        return ans;
        
    }
};