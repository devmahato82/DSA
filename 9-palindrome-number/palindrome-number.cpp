class Solution {
public:
    
    bool isPalindrome(int x) {
        if(x<0) return false;
        int a = x;
        long long ans = 0;
        while(a>0){
            int rem = a%10;
            a= a/10;
            ans = ans*10 + rem;
        }
        if(x == ans) return true;
        else return false;
    }
};