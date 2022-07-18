class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        // vector<vector<int>> dp(n+1, vector<int> (amount+1, 0));
        vector<int> dp(amount+1, 0);
        for(int i=1; i<=amount; i++){
            dp[i]=1e9;
            for(int j=1; j<=n; j++){
                if(i-coins[j-1]>=0){
                    dp[i] = min(dp[i], dp[i-coins[j-1]]+1);
                }
            }
        }
        return dp[amount]==1e9? -1: dp[amount];
    }
};