class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int maxLen=1;
        int start=0;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0; i<n; i++){
            dp[i][i]=true;
        }
        for(int i=0; i<n-1; i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                maxLen=2;
                start=i;
            } 
        }
        
        for(int k=3; k<=n; k++){
            for(int i=0; i<n-k+1; i++){
                int j= i+k-1;
                if(s[i]==s[j] and dp[i+1][j-1]){
                    dp[i][j]=1;
                    if(k>maxLen){
                        maxLen=k;
                        start=i;
                    }
                    
                }
            }
        }
        string res="";
        for(int i=start; i<start+maxLen; i++) res+=s[i];
        return res;
    }
};