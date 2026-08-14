class Solution {
    public boolean isIsomorphic(String s, String t) {
        if(s.length() != t.length()) return false;
        HashMap<Character, Character> hm = new HashMap<>();
        HashMap<Character, Character> hm1 = new HashMap<>();
        for(int i=0; i<s.length(); i++) {
            char c1 = s.charAt(i);
            char c2 = t.charAt(i);
            if(hm.containsKey(c1) && hm.get(c1) != c2) return false;
            if(hm1.containsKey(c2) && hm1.get(c2) != c1) return false;
            hm.put(c1,c2);
            hm1.put(c2,c1);
        }
        return true;


    }
}