class Solution {
public:
    bool isPalindrome(string &s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    int solve(int i, string&s,vector<int>&dp){
        int n=s.size();
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int cost = INT_MAX;
        for(int j=i; j<n; j++){
            if(isPalindrome(s,i,j)){
                cost = min(cost, 1+ solve(j+1, s,dp));
            }
        }
        return dp[i]=cost;
    }
    int minCut(string s) {
        vector<int> dp(s.size()+1, -1);
        return solve(0,s,dp)-1;
    }
};