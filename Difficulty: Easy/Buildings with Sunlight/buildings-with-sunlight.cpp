class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        int n = arr.size();
        int count =1;
        int maxheight = arr[0];
        for(int i=1; i<n; i++) {
            if(arr[i]>= maxheight) {
                count++;
                maxheight = arr[i];
            }
        }
        return count;
    }
};