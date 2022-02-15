class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n= nums.size();
        int high = n-1, low =0, mid =0;
        while(mid<=high){
            if(nums[mid]==0) mid++;
            else{
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }
        }
    }
};