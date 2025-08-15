class Solution {
    public int maxValueOfCoins(List<List<Integer>> piles, int k) {
        int n = piles.size();
        int[][] dp = new int[n+1][k+1];
        for(int[] ar : dp) {
            Arrays.fill(ar, -1);
        }
        
        List<int[]> pre = new ArrayList<>();
        for(List<Integer> pile : piles){
            pre.add(new int[pile.size() + 1]);
            for(int i=0; i<pile.size(); i++){
                pre.get(pre.size()-1)[i+1] = pile.get(i) + pre.get(pre.size()-1)[i];
            }
        }
        return traverse(0, k, dp, piles,pre);
    }

    int traverse(int curr, int k, int[][] dp, List<List<Integer>> piles, List<int[]> pre){
        if(curr >= piles.size()) return 0;
        if(k < 0) return 0;
        if(dp[curr][k] != -1) return dp[curr][k];
        
        int skipCurrent = traverse(curr+1, k, dp, piles, pre);
        int takeCurrent = 0;
        for(int i= 1; i<= Math.min(piles.get(curr).size(), k); i++){
            takeCurrent = Math.max(takeCurrent, pre.get(curr)[i] + traverse(curr + 1, k-i, dp, piles, pre));
        }
        dp[curr][k] = Math.max(takeCurrent, skipCurrent);
        return dp[curr][k];
    }
}