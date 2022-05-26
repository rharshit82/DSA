class Solution {
public:
    bool solve(vector<vector<int>> &dp, vector<int>& nums, int n, int sum){
        if(sum<0) return false;
        if(n==0) return sum==0;
        if(dp[n][sum]!=-1) return dp[n][sum];
        return dp[n][sum] = solve(dp,nums,n-1,sum-nums[n-1]) || solve(dp,nums,n-1,sum);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++) sum+=nums[i];
        if(sum%2!=0) return false;
        sum/=2;
        vector<vector<int>> dp(n+1, vector<int> (sum+1,-1));
        return solve(dp,nums,n,sum);
    }
};