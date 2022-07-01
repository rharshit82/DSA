class Solution {
public:
    
    int solve(string s, int i,vector<int> &dp){
        int n=s.size();
        if(i>=n) return 1;
        if(dp[i]!=-1) return dp[i];
        int res=0;
        int no = s[i]-'0';
        int no2=0;
        if(i+1<n){
             no2= no*10 + (s[i+1]-'0');
        }
        if(no>0) res+=solve(s,i+1,dp);
        if(no>0 and no2>0 and no2<=26) res+=solve(s,i+2,dp);
        return dp[i]=res;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1,-1);
        return solve(s,0,dp);
    }
};