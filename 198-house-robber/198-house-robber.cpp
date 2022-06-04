class Solution {
public:
    
    int help(int i, vector<int>&dp,vector<int>& nums){
        if(i>=nums.size()) return 0;
        if(i==nums.size()-1) return nums[i];
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(nums[i]+ help(i+2,dp,nums), help(i+1,dp,nums));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return help(0,dp,nums);
    }
};