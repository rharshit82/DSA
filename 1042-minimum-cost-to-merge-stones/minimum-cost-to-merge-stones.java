class Solution {
    public int mergeStones(int[] stones, int k) {
        int n = stones.length;
        if((n-1)%(k-1)!=0) return -1;
        int[] pre = new int[n+1];

        for(int i=0; i<n; i++){
            pre[i+1] = stones[i] + pre[i];
        }
        int[][] dp = new int[n][n];
        for(int len = 2; len<=n; len++){
            for(int l = 0; l + len <= n; l++){
                int r = l + len - 1;
                dp[l][r] = Integer.MAX_VALUE;
                for(int p=l; p<r; p+= k-1){
                    dp[l][r] = Math.min(dp[l][r], dp[l][p] + dp[p+1][r]);
                }

                if((len-1) % (k-1) == 0){
                    dp[l][r] += pre[r+1] - pre[l];
                }
            }
        }
        return dp[0][n-1] == Integer.MAX_VALUE ? -1 : dp[0][n-1];
    }
}