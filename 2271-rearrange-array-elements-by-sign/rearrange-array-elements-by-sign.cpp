class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> p;
        vector<int> n;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > 0) p.push_back(nums[i]);
            else n.push_back(nums[i]);
        }
        int j=0;
        for(int i=0 ; i<p.size(); i++ ){
            nums[j++] = p[i];
            nums[j++] = n[i];
        }
        return nums;

    }
};