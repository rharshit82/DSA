class Solution {
    public int longestPalindromeSubseq(String s) {
        int n = s.length();
        String t = new StringBuilder(s).reverse().toString();
        int[][] dp = new int[n][n];

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(s.charAt(i) == t.charAt(j)){
                    dp[i][j] = 1 + ((i-1 >=0 && j-1 >=0) ? dp[i-1][j-1] : 0);
                } else{
                    dp[i][j] = Math.max((i-1 >= 0 ? dp[i-1][j] : 0), (j-1 >=0 ? dp[i][j-1] : 0));
                }
            }
        }
        return dp[n-1][n-1];
    }
}