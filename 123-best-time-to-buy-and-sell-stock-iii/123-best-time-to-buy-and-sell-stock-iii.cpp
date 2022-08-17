class Solution {
public:
    int f(int ind, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>&dp){
        int n= prices.size();
        if(cap == 0 or ind == n) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        if(buy){
            int a = -prices[ind] + f(ind+1, 0, cap, prices, dp);
            int b = f(ind+1, 1, cap, prices, dp);
            return dp[ind][buy][cap] =max(a,b);
        }
        int a = prices[ind] + f(ind+1, 1, cap-1, prices, dp);
        int b = f(ind+1, 0, cap, prices, dp);
        return dp[ind][buy][cap]= max(a,b);
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int>(3, -1)));
        return f(0, 1, 2, prices, dp);
    }
};