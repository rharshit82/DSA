class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int low = 0, high=nums.size()-1;
        int mid=0;
        if(nums.size()==1) return nums;
        if(nums.size()==2){
            if(nums[1]%2==0) swap(nums[1],nums[0]);
            return nums;
        }
        while(mid<=high){
            if(nums[mid]%2==0){
                swap(nums[mid],nums[low]);
                mid++;
                low++;
                
            } else mid++;
        }
        return nums;
    }
};