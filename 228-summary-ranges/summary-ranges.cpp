class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        if(n==0) return ans;
        int first = nums[0];
        int last = nums[0];
        for(int i=1; i<n; i++) {
            if(last != nums[i]-1){
                if(first == last) ans.push_back(to_string(first));
                else ans.push_back(to_string(first)+"->"+ to_string(last));
                first = nums[i];
                last = nums[i];
            }
            else last = nums[i];
        }
        if(first == last) ans.push_back(to_string(first));
        else ans.push_back(to_string(first)+"->"+ to_string(last));
        return ans;
    }
};