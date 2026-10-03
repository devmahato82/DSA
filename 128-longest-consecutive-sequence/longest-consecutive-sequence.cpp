class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
    
        for(int i=0; i<n; i++) {
            s.insert(nums[i]);
        }

        int ans =0;
        for(int x : s) {
            int cnt =0;
            int current = x;
            if(s.find(current-1) == s.end()) {
                cnt++;
                current++;
                while(s.find(current) != s.end()) {
                    cnt++;
                    current++;
                }
            }
            ans = max(ans, cnt);
        }

        return ans;

    }
};