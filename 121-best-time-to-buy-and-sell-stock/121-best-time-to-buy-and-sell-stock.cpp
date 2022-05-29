class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int curr=0;
        int res = INT_MIN;
        if(n==1) return 0;
        for(int i=0; i<n-1; i++){
            curr+=prices[i+1]-prices[i];
            if(curr<0) curr=0;
            res=max(curr,res);
        }
        return res;
    }
};