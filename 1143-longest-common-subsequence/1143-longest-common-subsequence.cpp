class Solution {
public:
    int solve(vector<vector<int>> &dp, int i, int j,string &s, string &t){
        if(i==0 or j==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==t[j-1]) return dp[i][j]=1+ solve(dp,i-1,j-1,s,t);
        
        return dp[i][j]=max(solve(dp,i-1,j,s,t),solve(dp,i,j-1,s,t));
    }
  
   
    int longestCommonSubsequence(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1,-1));
        return solve(dp,n1,n2,s,t);
    }
};