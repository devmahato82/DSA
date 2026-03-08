class Solution {
public:
    int countTriples(int n) {
        int count =0;
        unordered_set<int> square;
        for(int i=1;i<=n; i++){
            int a = i*i;
            square.insert(a);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(square.find(i*i+j*j) != square.end()) count++;
            }
        }
        return count;
        
    }
};