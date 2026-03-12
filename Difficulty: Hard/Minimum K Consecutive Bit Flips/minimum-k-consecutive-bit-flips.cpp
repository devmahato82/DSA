class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
        int n= arr.size();
        queue<int>q;
        int flip =0;
        for(int i=0;i<n;i++){
            if(!q.empty() && q.front()<i) q.pop();
            if(q.size()%2 == arr[i]) {
                if(i+k-1 >= n) return -1;
                q.push(i+k-1);
                flip++;
            }
        }
        return flip;
    }
};