class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size();
        long long ans =0;
        for(int i=0; i<n; i++){
            // left = -2;
            //right = +2;
            // up = -1;
            // down = +1
            if(moves[i] == 'U') ans -= 1;
            if(moves[i] == 'D') ans += 1;
            if(moves[i] == 'L') ans -= 100;
            if(moves[i] == 'R') ans += 100;
        }
        return (ans == 0 ) ? true : false;
    }
};