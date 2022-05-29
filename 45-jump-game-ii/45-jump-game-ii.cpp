
class Solution {
public:
    int jump(vector<int>& nums) {
        int curreach=0;
        int maxreach=0;
        int jump=0;
        for(int i=0;i<nums.size();i++){
            if(i+nums[i]>maxreach){
                maxreach=i+nums[i];
            }
            if(curreach==i and i!=nums.size()-1){
                jump++;
                curreach=maxreach;
            }
        }
        return jump;
    }
};