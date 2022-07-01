class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        if(n==0) return 0;
        if(n==1) return nums[0];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        int res = 0;
        for(int i=2; i<n; i++){
            dp[i]= max(dp[i-1], nums[i]+ dp[i-2]);
        }
        vector<int> dp2(n,0);
        dp2[n-1]=nums[n-1];
        dp2[n-2]=max(nums[n-1],nums[n-2]);
        for(int i=n-3; i>=1; i--){
            dp2[i] = max(dp2[i+1],nums[i]+dp2[i+2]);
        }
        return max(dp[n-2],dp2[1]);
    }
};