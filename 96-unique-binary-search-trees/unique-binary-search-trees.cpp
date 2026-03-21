class Solution {
public:
long long binomial(int n){
    long long a = 1;
    for(int i=0;i<n ; i++){
        a = (a * (2*n-i)) / (i+1);
    }
    return a;
}
    long long numTrees(int n) {
        return binomial(n)/(n+1);
    }
};