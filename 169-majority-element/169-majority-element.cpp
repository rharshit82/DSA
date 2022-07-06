class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int majCount=1;
        int majEle=nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]==majEle){
                majCount++;
            } else{
                majCount--;
            }
            if(majCount==0){
                majEle=nums[i];
                majCount=1;
            }
        }
        return majEle;
    }
};