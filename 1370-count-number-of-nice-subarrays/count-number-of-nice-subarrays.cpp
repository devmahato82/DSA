class Solution {
public:
    int helper(vector<int>& nums, int k) {
        if(k < 0) return 0;
        int n = nums.size();
        int l=0, r=0, sum=0, count=0;
        while(r<n) {
            sum +=nums[r];
            while(sum > k) {
                sum -= nums[l];
                l++;
            }
            count += r-l+1;
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i]%2 == 0) nums[i] =0;
            else nums[i] =1;
        }

        return helper(nums,k) - helper(nums, k-1);

    }
};