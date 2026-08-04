class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxlen = 0;
        int l =0, r=0,maxf=0;
        int arr[26] = {0};
        while(r<n) {
           arr[s[r]-'A']++;
           maxf = max(maxf,arr[s[r]-'A']);
           if(r-l+1 - maxf > k){
            arr[s[l]-'A']--;
            l++;
           }
           if(r-l+1-maxf<= k) {
            maxlen = max(maxlen,r-l+1);
           }
           r++;

        }
        return maxlen;
    }
};