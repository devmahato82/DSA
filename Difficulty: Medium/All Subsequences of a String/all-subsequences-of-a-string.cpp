class Solution {
  public:
    vector<string> powerSet(string &s) {
        // Code here
        vector<string> ans;
        int n = s.length();
        for(int i=0; i<(1<<n); i++) {
            string a = "";
            for(int j=0; j<n; j++) {
                if(i&(1<<j)) {
                    a+=s[j];
                }
            }
            ans.push_back(a);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};