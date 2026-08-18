class Solution {
    public int totalFruit(int[] fruits) {
        int n = fruits.length;
        int maxc = Integer.MIN_VALUE;
        HashMap<Integer,Integer> hm = new HashMap<>();
        int l=0, r=0;
        while(r<n) {
            hm.put(fruits[r], hm.getOrDefault(fruits[r],0)+1);
            if(hm.size()>2) {
                if(hm.get(fruits[l]) >1){
                    hm.put(fruits[l],hm.get(fruits[l])-1);
                }
                else hm.remove(fruits[l]);
                l++;
            }
            maxc = Math.max(maxc, r-l+1);
            r++;
        }
        return maxc;

    }
}