class Solution {
public:
    int dp[21][2001];
    
    int dfs(int i, int &S, vector<int>&nums,int sum){
        if(i==nums.size()) {
            if(S==sum) return 1;
            else return 0;
        }
        if(dp[i][sum+1000]!=-1) return dp[i][sum+1000];
        return dp[i][sum+1000]=dfs(i+1, S, nums,sum+nums[i])+dfs(i+1, S, nums,sum-nums[i]);
        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return dfs(0,target,nums,0);
    }
};