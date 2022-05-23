class Solution {
public:
   int rob(vector<int>& nums) {
        int n=nums.size();
        int a=0;
        int b=nums[0];
        int c;
        for(int i=2; i<=n; i++){
            c=max(b,nums[i-1]+a);
            a=b;
            b=c;
        }
        return c;
    }
    int cob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2; i<=n; i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        return dp[n];
    }
};