class Solution {
    public int stoneGameVII(int[] stones) {
        int n = stones.length;
        int[] pre = new int[n + 1];

        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + stones[i];
        }
        int[][] dp = new int[n+1][n+1];
        
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                int removeLeft = pre[j + 1] - pre[i + 1]; 
                int removeRight = pre[j] - pre[i];   
                dp[i][j] = Math.max(removeLeft - dp[i+1][j], removeRight - dp[i][j-1]);  
            }
        }
        return dp[0][n-1];
    }
}