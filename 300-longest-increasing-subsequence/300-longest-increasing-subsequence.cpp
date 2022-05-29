class Solution {
public:
    int f(vector<int>& nums,vector<vector<int>>& dp,int ind, int prev){
        if(ind==nums.size()) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int len = f(nums,dp,ind+1,prev);
        if(prev==-1 or nums[ind]>nums[prev]){
            len=max(1+ f(nums,dp,ind+1,ind), len) ;
        }
        return dp[ind][prev+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(nums,dp,0,-1);
    }
};