class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        // code here
        vector<int> ans;
        for( int x : arr) {
            bool reduced = false;
            while( !ans.empty() && ( (ans.back()>0 && x<0) || (ans.back()<0 && x>0) )) {
                if(abs(ans.back()) == abs(x)){
                    reduced = true;
                    ans.pop_back();
                    break;
                }
                else if( abs(ans.back()) < abs(x) ) {
                    ans.pop_back();
                }
                else{
                    reduced = true;
                    break;
                }
            }
            if(!reduced) ans.push_back(x);
        }
        return ans;
    }
};