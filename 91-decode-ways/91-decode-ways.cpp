class Solution {
public:
    int ways(int i, string s, vector<int> &dp){
        int n=s.size();
        if(i>=n) return 1;
        if(dp[i]!=-1) return dp[i];
        int res=0;
        int no = (s[i]-'0');
        int no2=0;
        if(i+1<n){
            no2= 10*no + (s[i+1]-'0');
        }
        if(no>=1 and no<=26){
            res+=ways(i+1, s, dp);
            if(no2>=1 and no2<=26){
                res+= ways(i+2, s, dp);
            }
        } 
        return dp[i]=res;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1, -1);
        return ways(0,s,dp);
    }
};