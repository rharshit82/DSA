class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int mcount=1;
        int m=nums[0];
        for(int i=1;i<nums.size();i++){
            if(mcount<=0){
                m=nums[i];
            }
            if(nums[i]!=m){
                mcount--;
            }
            else{
                mcount++;
            }
        }
        return m;
    }
};