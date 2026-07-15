class Solution {
public:
    int trailingZeroes(int n) {
        int zeroes =0;
        int d =1;
        while(true) {
            d *=5;
            if(d>n) break;
            else{
                zeroes += n/d;
            }
        }
        return zeroes;
    }
};