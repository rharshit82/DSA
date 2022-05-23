class Solution {
public:
    int count(int m, int n, vector<vector<int>> &dp,int i, int j){
        if(i>=m or j>=n) return 0;
        if(i==m-1 and j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=count(m,n,dp,i+1,j) + count(m,n,dp,i,j+1);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return count(m,n,dp,0,0);
    }
};