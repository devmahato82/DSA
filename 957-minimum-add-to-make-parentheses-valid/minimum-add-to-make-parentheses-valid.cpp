class Solution {
public:
    int minAddToMakeValid(string s) {
        int open =0 , ans =0;
        for(auto x : s) {
            if(x=='(') open++;
            else {
                if(open >0) open--;
                else ans++;
            }
        }
        return open +ans;
    }
};