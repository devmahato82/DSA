class Solution {
    public boolean wordPattern(String pattern, String s) {
        int n = pattern.length();
        HashMap<Character, String> hm = new HashMap<>();
        HashMap<String, Character> revhm = new HashMap<>();
        
        ArrayList<String> sr = new ArrayList<>();
        int l=0;
        for(int i=0; i<s.length(); i++) {
            char ch = s.charAt(i);
            if(ch == ' '){
                sr.add(s.substring(l,i));
                l=i+1;
            }
        }
        sr.add(s.substring(l));

        if(sr.size() != pattern.length()) return false;

        for(int i =0; i<n; i++) {
            char ch = pattern.charAt(i);
            String c = sr.get(i);
            if(hm.containsKey(ch) && !hm.get(ch).equals(c)) return false;
            if(revhm.containsKey(c) && !revhm.get(c).equals(ch)) return false;
            hm.put(ch,c);
            revhm.put(c,ch);
        }
        return true;
    }
}