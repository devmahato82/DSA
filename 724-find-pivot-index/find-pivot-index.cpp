class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixsum;
        vector<int> suffixsum(n,0);
        int psum=0, ssum=0;
        for(int i=0; i<n; i++) {
            psum += nums[i];
            prefixsum.push_back(psum);
            ssum += nums[n-1-i];
            suffixsum[n-1-i] = ssum;
        }
        for(int i=0; i<n; i++) {
            if(prefixsum[i] == suffixsum[i]) return i;
        }
        return -1;
    }
};