class Solution {
public:
    int count(int i, int j, string s, string t, vector<vector<int>> &dp) {
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int nottake = count(i-1,j,s,t,dp);
        int take = 0;
        if(s[i] == t[j]) {
            take= count(i-1,j-1,s,t,dp);
        }
        return dp[i][j] = nottake +take;
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return count(n-1, m-1, s, t, dp);

        vector<vector<long long>> dp(n+1,vector<long long>(m+1,0));
        for(int i=0; i<=n; i++) dp[i][0] =1;
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m;j++) {
                long long nottake = dp[i-1][j];
                long long take =0;
                if(s[i-1]==t[j-1]) take = dp[i-1][j-1];
                dp[i][j] = min( (long long)INT_MAX, (take + nottake) );
            }
        }
        return (int)dp[n][m];
    }
};