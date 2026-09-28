class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        long long sum =0;
        for(int i=0;i<k;i++) {
            sum +=nums[i];
        }
        double ans = (double)sum/k;
        for(int i =k; i<n; i++) {
            sum = sum +nums[i] - nums[i-k];
            ans = max(ans , (double)sum/k);
        }
        return ans;
    }
};