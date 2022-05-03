class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size()<=1) return false;
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++) sum+=nums[i];
        if(sum%2!=0) return false;
        vector<vector<int>> dp(n+1,vector<int>(sum/2+1,-1));
        return helper(n,nums,sum/2,dp);
    }
    bool helper(int i, vector<int>& nums, int sum,vector<vector<int>>& dp){
        if(sum<=0 or i<=0) return sum==0;
        if(dp[i][sum]!=-1) return dp[i][sum];
        if(sum>=nums[i-1]) return dp[i][sum]=helper(i-1,nums,sum-nums[i-1],dp) or helper(i-1,nums,sum,dp);
        return dp[i][sum]=helper(i-1,nums,sum,dp);
    }
};