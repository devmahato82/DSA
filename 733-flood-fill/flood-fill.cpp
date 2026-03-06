class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int initialcolor){
        int n = image.size();
        int m = image[0].size();
        if(sr<0 || sc<0 ||sr>=n || sc>=m) return;
        if(image[sr][sc] != initialcolor) return;
        image[sr][sc] = color;
        dfs(image, sr+1, sc, color,initialcolor);
        dfs(image, sr, sc-1, color,initialcolor);
        dfs(image, sr-1, sc, color,initialcolor);
        dfs(image, sr, sc+1, color,initialcolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialcolor = image[sr][sc];
        if(initialcolor == color) return image;
        dfs(image, sr, sc, color, initialcolor);
        return image;
    }
};