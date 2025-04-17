class Solution {
    public long[] minimumCosts(int[] regular, int[] express, int expressCost) {
        int n = regular.length;

        long[][] dp = new long[n+1][2];
        long[] cost = new long[n];
        dp[0][0] = regular[0];
        dp[0][1] = express[0] + expressCost;
        cost[0] = Math.min(dp[0][0], dp[0][1]);
        for(int i=1; i<n; i++){
            dp[i][0] = Math.min(dp[i-1][0] + regular[i], dp[i-1][1] + regular[i]);
            dp[i][1] = Math.min(dp[i-1][1] + express[i], dp[i-1][0] + express[i] + expressCost);

            cost[i] = Math.min(dp[i][0], dp[i][1]);
        }
        return cost;
    }
}