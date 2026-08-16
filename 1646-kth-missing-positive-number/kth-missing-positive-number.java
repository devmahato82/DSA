class Solution {
    public int findKthPositive(int[] arr, int k) {
        int count =0;
        int ans=k;
        for(int i=0; i<arr.length; i++) {
            if(arr[i]<=k) {
                count++;
                ans =  k +count;
            }
            else if(arr[i]<=ans) ans++;
        }
        return ans;
    }
}