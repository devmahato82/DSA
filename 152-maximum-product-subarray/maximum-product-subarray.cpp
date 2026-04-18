class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mp = INT_MIN;
        for(int i=0; i<n; i++){
            int p = nums[i];
            mp = max(mp,p);
            for(int j=i+1; j<n; j++){
                p = p* nums[j];
                mp =max(mp,p);
            }
        }
        return mp;
    }
};