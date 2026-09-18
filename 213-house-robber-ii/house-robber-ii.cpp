class Solution {
public:
    int find(int i,int n, vector<int>& nums,vector<int>&dp) {
        if(i>=n) return 0;
        if(dp[i] != -1) return dp[i];
        int robhouse = nums[i] + find(i+2,n,nums,dp);
        int notrobhouse = find(i+1,n,nums,dp);
        return dp[i] = max(robhouse, notrobhouse);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        vector<int> dp1(n+2,-1);
        vector<int> dp2(n+2,-1);
       // if(n%2==0) 
        return max(find(0,n-1,nums,dp1), find(1,n,nums,dp2));
        //return max(max(nums[0],nums[n-1])+find(2,n-1,nums,dp1), find(1,n,nums,dp2));
    }
};