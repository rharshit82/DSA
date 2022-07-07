class Solution {
public:
    bool solve(string s1, string s2, string s3,int i, int j, int k,vector<vector<int>>&dp){
        if(i==s1.size() and j==s2.size() and k==s3.size()) return true;
        if(k==s3.size()) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        int a=false,b=false,c=false;
        if(i<s1.size() and s1[i]==s3[k]){
            a= solve(s1,s2,s3,i+1,j,k+1,dp);
        }
        if(j<s2.size() and s2[j]==s3[k]){
            b= solve(s1,s2,s3,i,j+1,k+1,dp);
        }
        return dp[i][j]= a or b;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1= s1.size();
        int n2= s2.size();
        int n=s3.size();
        vector<vector<int>> dp(n1+1, vector<int> (n2+1,-1));
        return solve(s1,s2,s3,0,0,0,dp);
    }
};