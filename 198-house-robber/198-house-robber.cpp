class Solution {
public:
    int count(int n, vector<int>&dp,vector<int>& nums){
        if(n==1) return nums[0];
        if(n<=0) return 0;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=max(count(n-1,dp,nums), nums[n-1] + count(n-2,dp,nums));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2; i<=n; i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        return dp[n];
    }
};