class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int res=0;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0; i<n; i++){
            dp[i][i]=true;
            res++;
        }
        for(int i=0; i<n-1; i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                res++;
            } 
        }
        
        for(int k=3; k<=n; k++){
            for(int i=0; i<n-k+1; i++){
                int j= i+k-1;
                if(s[i]==s[j] and dp[i+1][j-1]){
                    dp[i][j]=1;
                    res++;
                }
            }
        }
        return res;
    }
};