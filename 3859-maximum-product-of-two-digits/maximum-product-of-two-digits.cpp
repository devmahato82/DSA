class Solution {
public:
    int maxProduct(int n) {
        int max1 =INT_MIN, max2=INT_MIN;
        while(n>0) {
            int l = n%10;
            if(l>max1){
                max2 = max1;
                max1 =l;
            }
            else if(l>max2) {
                max2 = l;
            }
            n = n/10;
        }
        return max1*max2;
        
    }
};