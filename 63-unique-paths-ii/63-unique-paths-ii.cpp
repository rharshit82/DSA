class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& grid, int i, int j ){
        int m=grid.size();
        int n=grid[0].size();
        if(i>=m or j>=n or i<0 or j<0) return 0;
        if(grid[i][j]==1) return 0;
        if(i==m-1 and j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=dfs(grid,i+1,j) + dfs(grid,i,j+1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        dp.resize(m+1,vector<int>(n+1,-1));
        return dfs(grid,0,0);
    }
};