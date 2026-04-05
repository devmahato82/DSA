class Solution {
public:
    void reversepart(int x ,int y, vector<int>& nums){
        while(x<=y){
            int temp = nums[x];
            nums[x] = nums[y];
            nums[y] = temp;
            x++;
            y--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        reversepart(0,n-k-1,nums);
        reversepart(n-k,n-1,nums);
        reversepart(0,n-1,nums);

    }
};