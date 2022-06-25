class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int res = INT_MAX;
        int i=0;
        int sum=0;
        for(int j=0; j<n;j++){
            sum+=nums[j];
            if(sum>=target){
                while(sum>=target){
                sum-=nums[i];
                i++;
                }
            res= min(res, j-i+2);
            }
        }
        return res==INT_MAX?0:res;
    }
};