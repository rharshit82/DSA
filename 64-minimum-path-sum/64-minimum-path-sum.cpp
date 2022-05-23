class Solution {
public:
    int count(vector<vector<int>>& dp,vector<vector<int>>& grid,int n, int m){
        if(m<0 or n<0) return 0;
        if(m==0 and n==0) return grid[0][0];
        if(dp[n][m]!=-1) return dp[n][m];
        int top=INT_MAX,left=INT_MAX;
        if(n-1>=0) top = grid[n][m]+ count(dp,grid,n-1,m);
        if(m-1>=0) left = grid[n][m]+ count(dp,grid,n,m-1);
        return dp[n][m]=min(top,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(); int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return count(dp,grid,n-1,m-1);
    }
};