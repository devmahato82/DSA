class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        //create a map
        unordered_map<char,int> m;
        int r=0,l=0, maxl=0;
        while(r<n){
            while(m.find(s[r])!= m.end()){
                m[s[l]]--;
                if(m[s[l]] == 0) m.erase(s[l]);
                l++;
            }
            m[s[r]]++;
            int length = r-l+1;
            maxl = max(maxl,length);
            r++;
        }
        return maxl;
    }
};