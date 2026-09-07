class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();

        long long total = 1; // dp[0] = 1 (empty subsequence)
        vector<int> last(26, -1); // last occurrence of each char

        for(int i = 0; i < n; i++) {
            long long newTotal = (2 * total) % MOD;

            int ch = s[i] - 'a';
            if(last[ch] != -1) {
                // subtract subsequences counted before last occurrence
                newTotal = (newTotal - last[ch] + MOD) % MOD;
            }

            // update last[ch] to store the contribution of subsequences
            last[ch] = total;

            total = newTotal;
        }

        return (total - 1 + MOD) % MOD; // exclude empty subsequence
    }
};
