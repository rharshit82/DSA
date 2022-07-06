class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int res=INT_MIN;
        int curmin = INT_MAX;
        for(int i=0; i<n; i++){
            curmin = min(prices[i],curmin);
            res = max(res, prices[i]-curmin);
        }
        return res;
    }
};