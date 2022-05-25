class Solution {
public:
    int solve(vector<vector<int>>&dp, vector<vector<int>>& matrix, int row, int col){
        if(col<0 or col>=matrix[0].size()) return 1e9;
        if(dp[row][col]!=-1) return dp[row][col];
        if(row==matrix.size()-1) return matrix[row][col];
        int a = matrix[row][col]+ solve(dp,matrix,row+1,col);
        int b = matrix[row][col]+ solve(dp,matrix,row+1,col+1);
        int c = matrix[row][col]+ solve(dp,matrix,row+1,col-1);
        int res = min(a,min(b,c));
        return dp[row][col]=res;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int mx = INT_MAX;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0; i<m; i++){
            mx= min(solve(dp,matrix,0,i),mx);
        }
        return mx;
    }
};