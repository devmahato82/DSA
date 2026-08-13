class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int maxlen = Integer.MIN_VALUE;
        int l=0, r=0;
        HashMap<Character, Integer> hm = new HashMap<>();
        while(r<n) {
            char c = s.charAt(r);
           if(hm.containsKey(c) ) {
             l = Math.max(l,hm.get(c)+1);
           }
           hm.put(c, r);
           maxlen = Math.max(maxlen, r-l+1);
           r++;
        }
        return maxlen == Integer.MIN_VALUE ? 0:maxlen;
    }
}