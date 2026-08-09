class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int t=0;
        for(int x : nums) t+=x;
        int lsum=0;
        for(int i=0; i<n; i++){
            if(2*lsum + nums[i] == t) return i;
            lsum +=nums[i];
        }
        return -1;
    }
};