class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int ans =0;
        for(int i=0; i<n;i++) {
            int ind = s[i]-'a';
            int product = (26-ind)*(i+1);
            ans += product;
        }
        return ans;
    }
};