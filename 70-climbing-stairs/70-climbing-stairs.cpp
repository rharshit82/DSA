class Solution {
public:
    
    int count(int n){
        if(n==1 or n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=count(n-1) + count(n-2);
    }
    int dp[100000];
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return count(n);
    }
};