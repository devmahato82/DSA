

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        int n = arr.size();
        priority_queue<int> pq;
        vector<int> ans;
        ans.push_back(arr[n-1]);
        pq.push(arr[n-1]);
        for(int i=n-2; i>=0; i--){
            if(arr[i]>= pq.top()){
                ans.push_back(arr[i]);
                pq.push(arr[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};