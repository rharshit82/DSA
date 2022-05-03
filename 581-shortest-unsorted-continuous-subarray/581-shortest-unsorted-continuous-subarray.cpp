class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int before = nums[0];
        int end=-1;
        for(int i=1 ; i<nums.size(); i++){
            if(nums[i]<before) end=i;
            else before=nums[i];
        } 
        before = nums[nums.size()-1];
        int start=0;
        for(int i=nums.size()-2 ; i>=0; i--){
            if(nums[i]>before) start=i;
            else before=nums[i];
        } 
        return end-start+1;
    }
};