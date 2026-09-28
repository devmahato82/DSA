class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
       unordered_map<char,int> mp;
       int l=0, r=0;
       
       while(r<n) {
        mp[s[r]]++;
        while(mp[s[r]] >1) {
            mp[s[l]]--;
            l++;
        }
        ans = max(ans, r-l+1);
        r++;
       }
       return ans;

    }
};