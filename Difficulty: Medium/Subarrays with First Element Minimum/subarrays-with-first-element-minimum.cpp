class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        int n = arr.size();
        int count = 0;
        stack<int> s;
        for(int i=0;i<n;i++){
            while(s.size()!=0 && arr[i]<arr[s.top()]){
                int idx = s.top();
                s.pop();
                count += i-idx;
            }
            s.push(i);
        }
        while(s.size()!=0){
            int idx = s.top();
            s.pop();
            count += n-idx;
        }
        return count;
    }
};