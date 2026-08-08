class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        int l=0, r=0;
        while(r<n) {
            while(r <n-1 && nums[r] == nums[r+1]){
                r++;
            }
            nums[l] = nums[r];
            l++;
            r++;
            count++;
        }
        return count;
    }
};