class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int n1 = s.size(),n2 = t.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                } else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int len = n1+ n2 - dp[n1][n2];
        string res;
        int i=n1, j= n2;
        while(i>0 and j>0){
            if(s[i-1]==t[j-1]){
                res+=s[i-1];
                i--;
                j--;
            } else{
                if(dp[i-1][j]>dp[i][j-1]){
                    res+=s[i-1];
                    i--;
                } else{
                    res+=t[j-1];
                    j--;
                }
            }
        }
        while(i>0){
            res+=s[i-1];
            i--;
        }
        while(j>0){
            res+=t[j-1];
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};