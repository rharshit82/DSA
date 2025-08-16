class Solution {
    public int minCost(int n, int[] cuts) {
        int[] cutsPadded = new int[cuts.length + 2];
        cutsPadded[0] = 0;
        Arrays.sort(cuts);
        for (int i = 0; i < cuts.length; i++) {
            cutsPadded[i + 1] = cuts[i];
        }
        cutsPadded[cuts.length + 1] = n;
        int[][] dp = new int[cuts.length + 2][cuts.length + 2];

        for (int len = 1; len <= cutsPadded.length; len++) {
            for (int l = 0; l + len <= cutsPadded.length; l++) {
                int r = l + len - 1;
                dp[l][r] = Integer.MAX_VALUE;
                for (int k = l + 1; k < r; k++) {
                    dp[l][r] = Math.min(dp[l][r],
                            dp[l][k] + dp[k][r] + cutsPadded[r] - cutsPadded[l]);
                }
                if (dp[l][r] == Integer.MAX_VALUE) dp[l][r] = 0;

            }
        }
        return dp[0][cuts.length + 1];
    }
}