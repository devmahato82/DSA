class Solution {
public:
    int findGCD(vector<int>& nums) {
        int sn =INT_MAX, ln = INT_MIN;

        for(int i=0;i<nums.size(); i++) {
            if(nums[i]> ln) ln = nums[i];
            if(nums[i] < sn) sn = nums[i];
        }

        cout<<sn<<" "<<ln;

        while(sn!=0) {
            int temp = sn;
            sn = ln%sn;
            ln = temp;
        }
        return ln;

    }
};