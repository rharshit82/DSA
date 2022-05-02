class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int low = 0, high=nums.size()-1;
        int mid=0;
        
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