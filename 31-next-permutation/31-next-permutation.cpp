class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i;
        for(i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                break;
            }
        }
        if(i<0){
            reverse(nums.begin(),nums.end());
            return;
        }
        int k;
        for(k=n-1; k>=0; k--){
            if(nums[k]>nums[i]){
                break;
            }
        }
        swap(nums[k],nums[i]);
        reverse(nums.begin()+i+1,nums.end());
    }
};