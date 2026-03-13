class Solution {
public:
    bool rotateString(string s, string goal) {
        int n1 = s.size();
        int n2 = goal.size();
        if(n1!=n2) return false;
        for(int i=0;i<n1;i++){
            if(s==goal) return true;
            char A = s[0];
            s= s.substr(1);
            s=s+A;
        }
        return false;
    }
};