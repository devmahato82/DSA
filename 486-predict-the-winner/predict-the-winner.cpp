class Solution {
public:
    int helper(vector<int>& nums , int i , int j) {
        if(i==j) return nums[i];
        int left = nums[i] - helper(nums, i+1, j);
        int right = nums[j] - helper(nums, i, j-1);
        return max(left,right);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return (helper(nums, 0, n-1)) >=0;
    }
};