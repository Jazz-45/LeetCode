class Solution {
public:

    // dfs Approach
    void dfs(vector<vector<int>>& image ,int currRow, int currCol,int initialColor , int color){

        int m=image.size();
        int n=image[0].size();
        if(currRow<0 || currCol<0 || currRow>=m || currCol>=n) return; 
        if(image[currRow][currCol] != initialColor) return;

        image[currRow][currCol]=color;
        dfs(image,currRow-1,currCol,initialColor,color); // up
        dfs(image,currRow+1,currCol,initialColor,color); // down
        dfs(image,currRow,currCol+1,initialColor,color); // right
        dfs(image,currRow,currCol-1,initialColor,color); // left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image[sr][sc]==color) return image; // No DFS required
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
};