class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int curreach=0;
        int maxreach=0;
        int res=0;
        for(int i=0; i<n-1; i++){
            if(i+ nums[i]>maxreach){
                maxreach = i+nums[i];
            }
            if(curreach==i){
                res++;
                curreach=maxreach;
            }
        }
        return res;
    }
};