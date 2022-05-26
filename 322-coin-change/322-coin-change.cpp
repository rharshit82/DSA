class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        
        vector<int> dp(amount+1,1e8);
        dp[0]=0;
        for(int i=1; i<=amount; i++){
            int mn = 1e8;
            for(int j=1; j<=n; j++){
                if(i-coins[j-1]>=0)  mn= min(mn,1+ dp[i-coins[j-1]]);
            }
            dp[i]=mn;
        }
        return (dp[amount]>=1e8? -1: dp[amount]);
    }
};