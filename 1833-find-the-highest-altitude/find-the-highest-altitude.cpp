class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans =0;
        int presum =0;
        for(int i=0; i<gain.size(); i++) {
            presum = presum + gain[i];
            if(presum > ans) ans = presum;
        }
        return ans;
    }
};