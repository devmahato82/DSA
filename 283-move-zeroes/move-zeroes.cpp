class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n = arr.size();
        int l=0, r=0;
        while(r<n) {
            if(arr[r]!=0) {
                int temp = arr[r];
                arr[r] = arr[l];
                arr[l] = temp;
                l++;
            }
            r++;
        }
    }
};