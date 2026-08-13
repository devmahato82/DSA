class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int maxlen = Integer.MIN_VALUE;
        int l=0, r=0;
        HashSet<Character> hs = new HashSet<>();
        while(r<n) {
           while(hs.contains(s.charAt(r))) {
             hs.remove(s.charAt(l));
             l++;
           }
           hs.add(s.charAt(r));
           maxlen = Math.max(maxlen, r-l+1);
           r++;
        }
        return maxlen == Integer.MIN_VALUE ? 0:maxlen;
    }
}