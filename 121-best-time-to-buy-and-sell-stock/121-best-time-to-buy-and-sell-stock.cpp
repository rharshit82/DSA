class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int currmin= INT_MAX;
        int res = INT_MIN;
        for(int i=0; i<n; i++){
            currmin = min(currmin, prices[i]);
            res = max(res,prices[i]-currmin);
        }
        return res;
    }
};