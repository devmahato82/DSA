class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int nR = 0, nL = 0;
        for(int i=0;i<n; i++) {
            if(moves[i] == 'R') nR++;
            else if(moves[i] == 'L') nL++;
        }

        if(nR >=nL) return n - 2*nL;
        else return n - 2*nR;
    }
};