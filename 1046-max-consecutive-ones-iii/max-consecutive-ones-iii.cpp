class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zeroes =0, r=0, l=0, maxlen =0;
        queue<int> q;
        while(r<n) {
            if(nums[r] == 0) {
                q.push(r);
                zeroes++;
            }
            if(zeroes > k) {
                l = q.front()+1;
                q.pop();
                zeroes--;
            }
            int len = r-l+1;
            maxlen = max(maxlen, len);
            r++;  
        }
        return maxlen;
    }
};