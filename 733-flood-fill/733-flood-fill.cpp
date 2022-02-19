class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j,int m, int n, int newColor, int oldColor){
        if(i<0 or j<0 or i>=m or j>=n or image[i][j]!=oldColor) return;
        image[i][j]=newColor;
        dfs(image,i+1,j,m,n,newColor,oldColor);
        dfs(image,i-1,j,m,n,newColor,oldColor);
        dfs(image,i,j+1,m,n,newColor,oldColor);
        dfs(image,i,j-1,m,n,newColor,oldColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m=image.size();
        int n=image[0].size();
        if(image[sr][sc]!=newColor)
        dfs(image,sr,sc,m,n,newColor,image[sr][sc]);
        return image;
    }
};