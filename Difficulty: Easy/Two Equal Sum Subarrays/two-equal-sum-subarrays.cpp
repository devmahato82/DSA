class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        
        prefix[0] = arr[0];
        for(int i =1; i<n; i++) {
            prefix[i] = prefix[i-1] + arr[i];
        }
        
        suffix[n-1] = arr[n-1];
        for(int i= n-2; i>=0 ; i--){
            suffix[i] = suffix[i+1] + arr[i];
        }
        
        for(int i=0; i<n-1;i++) {
            if(prefix[i] == suffix[i+1]) return true;
        }
        return false;
    }
};
