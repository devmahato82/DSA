class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        // code here
        unordered_map<int, int> A;
        unordered_map<int, int> B;
        vector<int> ans;
        
        for(int i=0; i<a.size(); i++) {
            A[a[i]]++;
        }
        for(int i=0; i<b.size(); i++) {
            B[b[i]]++;
        }
        for(int i=0; i<c.size(); i++) {
            if( (A.find(c[i]) != A.end() ) && (B.find(c[i]) != B.end()) ) {
                ans.push_back(c[i]);
                A.erase(c[i]);
                B.erase(c[i]);
            }
        }
        return ans;
        
    }
};