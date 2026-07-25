class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> ans;
        unordered_map<int,int> nge;
        stack<int> s;
        s.push(nums2[n-1]);
        nge[nums2[n-1]] = -1;
        for(int i=n-2; i>=0; i--) {
            if(s.top() > nums2[i]) {
                nge[nums2[i]] = s.top();
            }
            else {
                while( !s.empty() && s.top() <= nums2[i]) {
                    s.pop();
                }
                if(s.empty()) nge[nums2[i]] = -1;
                else nge[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }
        for(auto x : nums1) {
            ans.push_back(nge[x]);
        }
        return ans;
    }
};