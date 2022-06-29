class Solution {
public:
    int LCS(int i, int j,string &s1, string&s2, vector<vector<int>>&dp){
        if(i<0 or j<0){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=1+ LCS(i-1,j-1,s1,s2,dp);
        }
        return dp[i][j]=max(LCS(i-1,j,s1,s2,dp), LCS(i,j-1,s1,s2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(),-1));
        return LCS(text1.size()-1, text2.size()-1,text1,text2,dp);
    }
};