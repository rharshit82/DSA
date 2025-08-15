class Solution {
    public int maxCoins(int[] nums) {
        List<Integer> paddedNums = new ArrayList<>();
        paddedNums.add(1);
        Arrays.stream(nums).forEach(paddedNums::add);
        paddedNums.add(1);
        int n = paddedNums.size();
        int[][] dp = new int[n][n];
        for(int length = 2; length<=n; length++){
            for(int l=0; l + length <= n; l++){
                int r = l + length - 1;
                for(int k=l+1; k<r; k++){
                    dp[l][r] = Math.max(dp[l][r], dp[l][k] + paddedNums.get(k) * paddedNums.get(l) * paddedNums.get(r) + dp[k][r]);
                }
            }
        }
        return dp[0][n-1];
            
    }
}