class Solution {
    public int minCost(int n, int[] cuts) {
        int m = cuts.length;
        Arrays.sort(cuts);
        
        int[] allCuts = new int[m + 2];
        allCuts[0] = 0;
        allCuts[m + 1] = n;
        for (int i = 0; i < m; i++) {
            allCuts[i + 1] = cuts[i];
        }
        int[][] dp = new int[m + 2][m + 2];
        int res = Integer.MAX_VALUE;
        for(int i = m; i>=1; i--){
            for(int j = i; j <= m; j++) {
                if(i > j) continue;
                dp[i][j] = Integer.MAX_VALUE;
                for(int k = i; k<=j; k++){
                    dp[i][j] = Math.min(dp[i][j], allCuts[j + 1] - allCuts[i - 1] + dp[k+1][j] + dp[i][k-1]);
                }
                
            }
        }
        return dp[1][m];
    }
}