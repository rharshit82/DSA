class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        int peak=1;
        int valley=1;
        for(int i=1; i<n; i++){
            if(nums[i-1]<nums[i]){
                peak = valley+1;
            } else if(nums[i-1]>nums[i]){
                valley= peak+1;
            }
        }
        return max(peak,valley);
    }
};