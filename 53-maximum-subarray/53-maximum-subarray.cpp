class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=INT_MIN;
        int n=nums.size();
        int curr=0;
        for(int i=0; i<n; i++){
            curr+=nums[i];
            res = max(res, curr);
            if(curr<0) curr=0;
        }
        return res;
    }
};