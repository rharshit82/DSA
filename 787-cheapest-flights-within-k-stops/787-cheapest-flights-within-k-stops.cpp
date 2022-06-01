class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(n, vector<int> (n, 1e9));
        int len = flights.size();
        int cycles = k;
        if(k<n-1) cycles++;
        dp[0][src] = 0;        
        for(int i=1; i<=cycles; i++){
            for(int j=0; j<len; j++){
                int from = flights[j][0];
                int to = flights[j][1];
                int weight= flights[j][2];
                dp[i][src] = dp[i-1][src]; //Every cycle src weight should be 0
                dp[i][to] = min(dp[i-1][to],min(dp[i][to], dp[i-1][from]+weight)); // From previous cycle To node, From previous Cycle From Node + weight, previously calculated value
            }
        }
        return (dp[cycles][dst]==1e9? -1: dp[cycles][dst]);
    }
};