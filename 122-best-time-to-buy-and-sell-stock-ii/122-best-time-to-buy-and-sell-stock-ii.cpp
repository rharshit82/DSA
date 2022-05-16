class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr=0;
        int res=0;
        for(int i=0; i<prices.size()-1; i++){
            int diff=prices[i+1]-prices[i];
            if(diff>0)
                curr+=diff;
            res=max(curr,res);
        }
        return res;
    }
};