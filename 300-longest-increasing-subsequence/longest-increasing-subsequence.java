class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int res = 0;
        int[][] dp = new int[n+1][n+1];
        for(int[] arr : dp){
            Arrays.fill(arr, -1);
        }
        return findRes(0, -1, nums, dp);
    }

    int findRes(int curr, int prev, int[] nums, int[][] dp){
        if(curr == nums.length) return 0;
        if (dp[curr][prev + 1] != -1) return dp[curr][prev + 1];
        if(prev == -1 || nums[curr] > nums[prev]){
            dp[curr][prev+1] = Math.max(dp[curr][prev+1], 1 + findRes(curr+1, curr, nums, dp));
        }
        dp[curr][prev+1] = Math.max(dp[curr][prev+1], findRes(curr+1, prev, nums, dp));
        return dp[curr][prev+1];
    }
}