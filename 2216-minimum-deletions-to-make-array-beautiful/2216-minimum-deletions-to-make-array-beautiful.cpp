class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int res= 0;
        int i = 0;
        while(i<n-1){
            if(nums[i] == nums[i+1]){
                res++;
                i++;
            } else{
                i+=2;
            }
        }
        if(i==n-1) res++;
        return res;
    }
};