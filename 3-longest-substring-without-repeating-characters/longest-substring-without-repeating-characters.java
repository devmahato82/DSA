class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int maxlen = Integer.MIN_VALUE;
        int l=0, r=0;
        HashMap<Character, Integer> hm = new HashMap<>();
        while(r<n) {
           if(hm.containsKey(s.charAt(r))) {
             l = Math.max(l,hm.get(s.charAt(r))+1);
           }
           hm.put(s.charAt(r), r);
           maxlen = Math.max(maxlen, r-l+1);
           r++;
        }
        return maxlen == Integer.MIN_VALUE ? 0:maxlen;
    }
}