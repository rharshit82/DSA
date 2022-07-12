class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int res=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='1' and i>=1 and j>=1){
                    dp[i][j] = 1+ min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                } else{
                    dp[i][j]=matrix[i][j]-'0';
                }
                res = max(dp[i][j], res);
            }
        }
        return res*res;
    }
};