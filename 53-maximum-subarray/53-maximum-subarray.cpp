class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        int res = INT_MIN;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            res=max(res,sum);
            if(sum<0) sum=0;
        }
        return res;
    }
};