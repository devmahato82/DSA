class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zeroes =0, r=0, l=0, maxlen =0;
        while(r<n) {
            if(nums[r] == 0) zeroes++;
            while(zeroes > k) {
                if(nums[l] == 0) zeroes--;
                l++;
            }
            int len = r-l+1;
            maxlen = max(maxlen, len);
            r++;  
        }
        return maxlen;
    }
};