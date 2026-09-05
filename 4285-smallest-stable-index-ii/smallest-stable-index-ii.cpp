class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ps(n,INT_MAX);
        for(int i=n-1 ; i>=0; i--) {
            if(i==n-1) ps[i] = nums[i];
            else {
                if(nums[i]<ps[i+1]) {
                    ps[i] = nums[i];
                }
                else ps[i] = ps[i+1];
            }
        }
        int minindex = -1;
        int maxi = nums[0];
        for(int i=0; i<n; i++) {
            maxi = max(maxi,nums[i]);
            if((maxi-ps[i]) <= k) {
                minindex = i;
                break;
            }
        }
        return minindex;
    }
};