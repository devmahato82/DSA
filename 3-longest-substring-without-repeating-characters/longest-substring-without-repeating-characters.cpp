class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l=0; 
        int maxlength =  0;
        unordered_set<char> seen;
        for(int r=0; r<n; r++) {
            while(seen.count(s[r])){
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            int length =  r-l+1;
            maxlength = max(maxlength,length);
        }
        
        return maxlength;
    }
};