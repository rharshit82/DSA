class Solution {
public:
    long long canDo(vector<int>&nums, int x){
        long long sum = 0;
        for(auto ele: nums){
            sum+= abs(ele-x);
        }
        return sum;
    }
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return canDo(nums,nums[n/2]);
    }
};