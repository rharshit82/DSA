class Solution {
    public int minSideJumps(int[] obstacles) {
        int n = obstacles.length-1;
        int[] dp = new int[4];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[1] = 1;
        dp[2] = 0;
        dp[3] = 1;

        for(int i=1; i<=n; i++){
            for(int k=1; k<=3; k++){
                if(obstacles[i] == k){
                    dp[k] = Integer.MAX_VALUE;
                }
            }

            for(int k=1; k<=3; k++){
                if(obstacles[i] == k) continue;
                for(int other = 1; other<=3; other++){
                    if(k != other && dp[other]!=Integer.MAX_VALUE){
                        dp[k] = Math.min(dp[k], dp[other]+1);
                    }
                }
            }
        }
        return Math.min(dp[1], Math.min(dp[2], dp[3]));
    }
}