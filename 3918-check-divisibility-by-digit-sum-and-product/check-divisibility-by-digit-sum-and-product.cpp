class Solution {
public:
    bool checkDivisibility(int n) {
        int t =n;
        int sum =0,product=1;
        while(t>0){
            int rem = t%10;
            sum += rem;
            product *= rem;
            t = t/10;
        }
        
        return (n%(product+sum)==0 );
    }
};