class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_set<int> square;
        for(int i=0;i<n;i++){
            arr[i] = arr[i]*arr[i];
            square.insert(arr[i]);
        }
        for(int i=0; i<n;i++){
            for(int j=i+1;j<n;j++){
                if(square.find(arr[i]+arr[j]) != square.end()) return true;
            }
        }
        
        return false;
    }
};