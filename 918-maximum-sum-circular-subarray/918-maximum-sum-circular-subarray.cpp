class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;
        int mn = INT_MAX;
        int curr1=0;
        int curr2=0;
        int tot=0;
        for(int i=0; i<n; i++){
            tot+=nums[i];
            curr1+=nums[i];
            curr2+=nums[i];
            mx = max(mx, curr1);
            mn = min(mn, curr2);
            if(curr1<0) curr1=0;
            if(curr2>0) curr2=0;
        }
        if(mn == tot) return mx;
        return max(mx, tot-mn);
    }
};