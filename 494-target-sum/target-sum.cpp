class Solution {
public:
    int helper(int ind, int target, vector<int> &nums) {
        if(ind==0){
            if(target == nums[0] && target == -nums[0]) return 2;
            if(target-nums[ind]==0 || target+nums[ind] ==0) return 1;
            else return 0;
        }
        int plus = helper(ind-1, target+nums[ind],nums);
        int minus = helper(ind-1, target-nums[ind], nums);
        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return helper(n-1,target, nums);
    }
};