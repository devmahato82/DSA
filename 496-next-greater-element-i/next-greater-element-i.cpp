class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> ans(n,-1);
        unordered_map<int,int> m;
        vector<int> help(nums2.size(),-1);
        for(int i=0; i<nums2.size()-1; i++) {
            for(int j=i+1; j<nums2.size();j++){
                if(nums2[j]> nums2[i]) {
                    help[i] = nums2[j];
                    break;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<nums2.size(); j++) {
                if(nums1[i] == nums2[j] ){
                    ans[i] = help[j];
                    break;
                }
            }
        }
        return ans;
    }
};