class Solution {
public:
    int helper(int ind1, int ind2, string s, string rev, vector<vector<int>> &dp) {
        if(ind1<0 || ind2<0) return 0;
 
        if(dp[ind1][ind2] !=-1) return dp[ind1][ind2];
        if(s[ind1] == rev[ind2]) return dp[ind1][ind2] = 1+helper(ind1-1, ind2-1, s, rev,dp);
        return dp[ind1][ind2] =  max(helper(ind1, ind2-1, s, rev, dp), helper(ind1-1, ind2, s, rev, dp));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string rev = s;
        reverse(rev.begin(), rev.end());
        //vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        //return helper(n-1, n-1,s,rev,dp);
        vector<int> prev(n+1,0);
        for(int ind1=1; ind1<=n; ind1++){
            vector<int> curr(n+1,0);
            for(int ind2=1; ind2<=n; ind2++) {
                if(s[ind1-1] == rev[ind2-1]) curr[ind2] = 1+ prev[ind2-1];
                else curr[ind2] =  max(curr[ind2-1], prev[ind2] );
            }
            prev = curr;
        }
        return prev[n];
    }
};