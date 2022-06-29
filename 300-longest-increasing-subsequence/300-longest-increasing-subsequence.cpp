class Solution {
public:
    int solve(int i, int last, vector<int>&nums, vector<vector<int>>& dp){
        int n=nums.size();
        if(i>n){
            return 0;
        }
        if(dp[i][last]!=-1) return dp[i][last];
        
        if(last==0){
            int a = solve(i+1,last,nums,dp);
            int b = 1+ solve(i+1,i,nums,dp);
            return dp[i][last]=max(a,b);
        }
        int b = solve(i+1,last,nums,dp);
        if(nums[i-1]>nums[last-1])
            b= max(b,1+ solve(i+1,i,nums,dp));
        
        return dp[i][last]=b;
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return solve(1,0,nums,dp);
    }
};