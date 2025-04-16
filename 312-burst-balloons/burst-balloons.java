class Solution {
    public int maxCoins(int[] nums) {
        int n = nums.length;
        int arr[] = new int[n+2];
        arr[0] = 1;
        for(int i=1; i<=n; i++) arr[i] = nums[i-1];
        arr[n+1] = 1;

        int[][] dp = new int[n+2][n+2];
        for(int len = 2; len<= n+1; len++){
            for(int i = 0; i+len <=n+1; i++){
                int j = i + len;
                dp[i][j] = Integer.MIN_VALUE;
                for(int k = i+1; k<j; k++){
                    dp[i][j] = Math.max(dp[i][j], arr[i]*arr[k]*arr[j] + dp[k][j] + dp[i][k]);
                }
            }
        }
        return dp[0][n+1];

    }
}