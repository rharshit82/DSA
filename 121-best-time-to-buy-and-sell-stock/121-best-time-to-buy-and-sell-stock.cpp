class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minsofar = INT_MAX;
        int res= INT_MIN;
        for(int i=0;i<prices.size();i++){
            minsofar= min(minsofar, prices[i]);
            res= max(res, prices[i]- minsofar);
        }
        return res;
    }
};