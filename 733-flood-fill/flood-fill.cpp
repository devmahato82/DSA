class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int initialcolor = image[sr][sc];
        if(initialcolor == color) return image;
        image[sr][sc] = color;

        queue<pair<int, int>> q;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        q.push({sr,sc});
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0; i<4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow>=0 && nrow <m && ncol>=0 && ncol<n && image[nrow][ncol] == initialcolor ){
                    q.push({nrow,ncol});
                    image[nrow][ncol] = color;
                }
            }
        }
        return image;

    }
};