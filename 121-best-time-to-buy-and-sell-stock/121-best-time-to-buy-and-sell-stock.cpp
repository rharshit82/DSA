class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=INT_MAX;
        int res=INT_MIN;
        int n =prices.size();
        for(int i=0; i<n; i++){
            mn = min(prices[i],mn);
            res=max(res,prices[i]-mn);
        }
        return res;
    }
};