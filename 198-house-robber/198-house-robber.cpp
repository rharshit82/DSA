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
        vector<int> dp(n+1,-1);
        return count(n,dp,nums);
    }
};