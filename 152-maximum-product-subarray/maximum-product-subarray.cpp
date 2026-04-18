class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxprod = nums[0];
        int minprod = nums[0];
        int ans  =nums[0];
        for(int i=1; i<n; i++) {
            int curr =  nums[i];
            if(curr < 0) swap(minprod, maxprod);
            maxprod = max(curr, maxprod* curr);
            minprod = min(curr, minprod*curr);
            ans = max(ans, maxprod);
        }
        return ans;
    }
};