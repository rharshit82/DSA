class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = INT_MIN;
        int curr=0;
        if(prices.size()==1)  return 0;
        for(int i=0; i<prices.size()-1; i++){
            int diff=prices[i+1]-prices[i];
            curr+=diff;
            if(curr<0) curr=0;
            res=max(curr,res);
        }
        return res;
    }
};