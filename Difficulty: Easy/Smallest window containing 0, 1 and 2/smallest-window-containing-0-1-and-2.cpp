class Solution {
  public:
    int smallestSubstring(string s) {
        // code here
        int n = s.size();
        int l=0, r=0;
        int ans = INT_MAX;
        unordered_map<char,int> mp;
        while(l<=r && r<n) {
            mp[s[r]]++;
            while(mp.size() == 3) {
                int len = r-l+1;
                ans = min(len, ans);
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            r++;
            
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};
