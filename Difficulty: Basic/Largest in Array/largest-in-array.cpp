class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int maxi = INT_MIN;
        for(int i=0; i<arr.size(); i++) {
            if(maxi <arr[i]) maxi = arr[i];
        }
        return maxi;
    }
};
