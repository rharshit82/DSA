class Solution {
public:
    
    int dp[200][200][50];
    
    int solve(vector<int>& houses, vector<vector<int>>& cost, int target, int last, int i){
        if(target<0) return 1e9;
        int n=cost[0].size();
        if(i>=houses.size()) return (target==0)?target: 1e9;
        if(dp[i][target][last]!=-1)return dp[i][target][last];
        if(houses[i]!=0){
            if(last!=houses[i]) target--;
            return solve(houses,cost,target,houses[i],i+1);
        }
        int res = 1e9;
        for(int k=1; k<=n; k++){
            res = min(res,cost[i][k-1]+ solve(houses,cost,target-(last!=k?1:0),k,i+1) );
        }
        return dp[i][target][last]=res;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int res = solve(houses,cost,target,0,0);
        return res==1e9? -1: res;
    }
};