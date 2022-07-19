class Solution {
public:
    // AP if Diff Same for All Array Elements
    
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(1001,0));
        int res=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                int diff = nums[i]- nums[j]+500;
            // We simply put:
            // int diff = nums[i] - nums[j] +500;
            // this will ensure the index: diff is between 0 and 1000, 
                // since the maximum can be 1000,               
                // the size of the one dimensional dp should be 1001
                dp[i][diff] = (dp[j][diff]> 0)? dp[j][diff]+1: 2;
                res = max(res, dp[i][diff]);
            }
        }
        return res;
    }
};