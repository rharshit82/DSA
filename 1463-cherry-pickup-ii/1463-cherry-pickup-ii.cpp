class Solution {
public:
    int solve(vector<vector<vector<int>>>&dp, int i, int j1, int j2,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
    return -1e9;
        if(i==n-1) {
            if(j1==j2) return grid[i][j1];
            return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int mx = INT_MIN;
        for (int di = -1; di <= 1; di++) {
            int x;
            for (int dj = -1; dj <= 1; dj++) {
                if(j1==j2)
                    x = grid[i][j1]+ solve(dp, i+1, j1+di, j2+ dj, grid);
                else
                    x = grid[i][j1]+ grid[i][j2]+ solve(dp, i+1, j1+di, j2+ dj, grid);
                mx=max(x,mx);
            }
            
        }
        return dp[i][j1][j2]=mx;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return solve(dp,0,0,m-1,grid);
    }
};