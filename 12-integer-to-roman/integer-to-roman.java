class Solution {
    public String intToRoman(int num) {
        List<Integer> val = Arrays.asList(1000,900,500,400,100,90,50,40,10,9,5,4,1);
        List<String> cha = Arrays.asList("M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I");

        StringBuilder ans = new StringBuilder();
        
        for(int pos =0; pos<val.size(); pos++) {
            while(num >= val.get(pos)) {
                ans.append(cha.get(pos));
                num -= val.get(pos);
            }
        }
        return ans.toString();
    }
}