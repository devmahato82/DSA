class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        priority_queue<int> mx;
        priority_queue<int,vector<int>, greater<int>> mn;
        for(int i=0;i<nums.size();i++){
            mx.push(nums[i]);
            mn.push(nums[i]);
        }
        int a =mx.top();
        mx.pop();
        int b = mx.top();
        int c = mn.top();
        mn.pop();
        int d = mn.top();
        return (a*b)-(c*d);
    }
};