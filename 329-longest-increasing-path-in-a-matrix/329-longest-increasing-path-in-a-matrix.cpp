class Solution {
public:
    
    int dfs(int i, int j, vector<vector<int>>& matrix,int last,vector<vector<int>>&dp){
        int n=matrix.size();
        int m=matrix[0].size();
        if(i<0 or j<0 or i>=n or j>=m or matrix[i][j]<=last) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int a = dfs(i+1,j,matrix,matrix[i][j],dp);
        int b = dfs(i-1,j,matrix,matrix[i][j],dp);
        int c = dfs(i,j+1,matrix,matrix[i][j],dp);
        int d = dfs(i,j-1,matrix,matrix[i][j],dp);
        return dp[i][j]=1 + max(a,max(b,max(c,d)));
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int res=0;
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                res = max(res, dfs(i,j,matrix,-1,dp));
            }
        }
        return res;
    }
};