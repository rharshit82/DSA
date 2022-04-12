class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int res=INT_MIN;
        vector<int> dp(n,0);
        dp[0]=1;
        for(int i=1 ;i<n; i++){
            int mx=0;
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i]){
                    mx = max(mx, dp[j]);
                }
            }
            dp[i]=mx+1;
            res=max(dp[i],res);
        }
        return res;
    }
};