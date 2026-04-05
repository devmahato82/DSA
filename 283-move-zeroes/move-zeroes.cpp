class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,0);
        int idx = 0;
        for(int i=0; i<n;i++){
            if(arr[i] != 0) ans[idx++] = arr[i];
        }
        arr = ans;

    }
};