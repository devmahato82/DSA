class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
        int n = s.size();

        long long total = 1; 
        vector<int> last(26, -1); 

        for(int i = 0; i < n; i++) {
            long long newTotal = (2 * total) % MOD;

            int ch = s[i] - 'a';
            if(last[ch] != -1) {
                newTotal = (newTotal - last[ch] + MOD) % MOD;
            }

            last[ch] = total;

            total = newTotal;
        }

        return (total - 1 + MOD) % MOD;
    }
};
