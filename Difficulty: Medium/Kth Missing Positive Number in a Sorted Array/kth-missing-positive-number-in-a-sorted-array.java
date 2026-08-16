class Solution {
    public int kthMissing(int[] arr, int k) {
        // code here
        int l=0, h=0, mid =0;
        while(l<=h) {
            mid = l+(h-l)/2;
            if(arr[mid]>k) h= mid-1;
            else l = mid+1;
        }
        int ans = k+mid;
        for(int i= mid; i< arr.length;i++) {
            if(arr[i]<=ans) ans++;
        }
        return ans;
    }
}