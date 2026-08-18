class Solution {
    public int characterReplacement(String s, int k) {
        int[] arr = new int[26];
        int maxlen =0, maxf=0, l=0, r=0;
        while(r<s.length()) {
            char ch = s.charAt(r);
            arr[ch-'A']++;
            maxf = Math.max(maxf,arr[ch-'A']);
            if(r-l+1-maxf > k ) {
                arr[s.charAt(l)-'A']--;
                l++;
            }
            if(r-l+1-maxf <=k) {
                maxlen = Math.max(maxlen, r-l+1);
            }
            r++;
        }
        return maxlen;
        
    }
}