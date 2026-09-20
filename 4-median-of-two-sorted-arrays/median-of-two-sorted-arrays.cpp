class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> ans;
        int l=0, r=0;
        while(l<m && r<n) {
            if(nums1[l] <= nums2[r]){
                ans.push_back(nums1[l]);
                l++;
            }
            else{
                ans.push_back(nums2[r]);
                r++;
            }
        }
        while(l<m) {
            ans.push_back(nums1[l]);
            l++;
        }

        while(r<n) {
            ans.push_back(nums2[r]);
            r++;
        }
        int a = ans.size();
        int mid = a/2;
        if(a%2==0) {
            cout<<ans[mid] <<" " <<ans[mid-1];
            double b = (ans[mid-1]+ans[mid]);
            return b/2;
        }
        else return ans[mid];
    }
};