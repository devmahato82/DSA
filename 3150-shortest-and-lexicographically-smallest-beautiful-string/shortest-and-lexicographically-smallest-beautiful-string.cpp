class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans ="";
        int l=0, r=0;
        int oc=0;
        while(r<n){
            if(s[r]=='1') oc++;
            while(oc>k) {
                if(s[l]=='1') oc--;
                l++;
            }
            while (oc == k && s[l] == '0') {
                l++;
            }
            if(oc==k) {
                string temp = s.substr(l, r-l+1);
                if (ans.empty() || temp.size() < ans.size() ||
                   (temp.size() == ans.size() && temp < ans)) {
                    ans = temp;
                }
            }
            r++;
        }
        return ans;
    }
};