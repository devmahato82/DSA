class Solution {
public:
    string minWindow(string s, string t) {
        int n= s.length();
        int m = t.length();
        int minlen = INT_MAX;
        int sindex =-1;
        unordered_map<char, int> mp;
        for(int i=0; i<m; i++){
            mp[t[i]]++;
        }
        int l=0, r=0,count =0;
        while(r<n){
            if(mp.find(s[r]) != mp.end()){
                if(mp[s[r]]>0) {
                    count++;
                }
                mp[s[r]]--;
            }
            else mp[s[r]]--;
           
            while(count == m){
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    sindex= l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) count--;
                l++;
            }
            r++;
        }
        return sindex == -1 ? "" : s.substr(sindex,minlen);
    }
};