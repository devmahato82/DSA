class Solution {
public:
    int count0(string s){
        int count=0;
        while(s.size()>0){
            int n = s.size();
            if(s[n-1] == '0') count++;
            s.pop_back();
        }
        return count;
    }
    int count1(string s){
        int count =0;
        while(s.size()>0){
            int n= s.size();
            if(s[n-1] == '1') count++;
            s.pop_back();
        }
        return count;
    }
    int maxScore(string s) {
        int n = s.size();
        int mx= INT_MIN;
        for(int i=0;i<n-1;i++){
            string left = s.substr(0,i+1);
            string right = s.substr(i+1);
            int leftcount = count0(left);
            int rightcount = count1(right);
            if(mx<(leftcount+rightcount)) mx = leftcount+rightcount;
        }
        return mx;

    }
};