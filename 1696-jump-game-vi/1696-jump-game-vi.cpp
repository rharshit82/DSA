class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> dq;
        int n=nums.size();
        vector<int> dp(n);
        dp[0]=nums[0];
        dq.push_front(0);
        for(int i=1; i<n; i++){
            if(i-k>dq.front()) dq.pop_front();
            dp[i] = nums[i] + dp[dq.front()];
            while(!dq.empty() and dp[i]>dp[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }
        return dp[n-1];
    }
};