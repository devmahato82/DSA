class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        int mini = INT_MAX;
        for(int i=0; i<n; i++) {
            s.insert(nums[i]);
        }
        int ans =0;
        for(int x : nums) {
            int cnt =1;
            int current =x;
            while(s.find(current-1) != s.end()) {
                cnt++;
                s.erase(current-1);
                current = current -1;
            }
            current = x;
            while(s.find(current+1) != s.end()) {
                cnt++;
                s.erase(current+1);
                current = current +1;
            }
            ans = max(cnt, ans);
        }
        return ans;

    }
};