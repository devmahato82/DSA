class Solution {
    public boolean isHappy(int n) {
        HashSet<Integer> hs = new HashSet<>();
        while(n!=1 && !hs.contains(n)){
            hs.add(n);
            int sum =0;
            while(n>0) {
                int rem = n%10;
                sum += Math.pow(rem,2);
                n = n/10;
            }
            n = sum;
        }
        return n==1? true: false;
    }
}