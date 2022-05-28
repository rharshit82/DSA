class Solution {
public:
    bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(i<0 and j<0) return 1;
        if(i<0 and j>=0) return 0;
        if(j<0 and i>=0){
            for(int k=0; k<=i; k++){
                if(p[k]!='*') return 0;
            }
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(p[i]==s[j] or p[i]=='?') return dp[i][j]=f(i-1,j-1,s,p,dp);
        if(p[i]=='*') return dp[i][j]= ((f(i,j-1,s,p,dp)==1 or f(i-1,j,s,p,dp)==1)?1:0);
        return dp[i][j]=0;
    }
    bool isMatch(string s, string p) {
        int n=p.size();
        int m=s.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return f(n-1,m-1,s,p,dp);
    }
};