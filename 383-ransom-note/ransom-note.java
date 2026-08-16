class Solution {
    public boolean canConstruct(String ransomNote, String mag) {
        HashMap<Character,Integer> hm = new HashMap<>();
        for(int i =0; i<mag.length();i++){
            char ch = mag.charAt(i);
            hm.put(ch, hm.getOrDefault(ch,0)+1);
        }
        for(int i=0; i< ransomNote.length(); i++) {
            char ch = ransomNote.charAt(i);
            if(hm.containsKey(ch) && hm.get(ch) >0) {
                hm.put(ch,hm.get(ch)-1);
            }
            else return false;
        }
        return true;
    }
}