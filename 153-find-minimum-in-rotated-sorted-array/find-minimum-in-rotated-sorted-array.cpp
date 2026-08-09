class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0 , end = n-1 ;
        int min;
        // Base case
        if(n==1){
            return nums[0];
        }
        if(nums[0]<nums[n-1]){
            return nums[0];
        } 

        while(start<=end){

            int mid = end + (start-end)/2;

            if(nums[mid]>=nums[0]){
                // Left side sorted , right ko move karo
                start = mid+1;
            }
            else{
                min = nums[mid];
                end = mid-1;
            }
        }

        return min;
        
    }
};