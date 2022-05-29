
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachind=0,i;
        for(i=0;i<nums.size();i++){
            if(i>reachind){
                return false;
            }
            reachind=max(reachind,i+nums[i]);
        }
        if(i!=nums.size())
            return false;
        return true;
    }
};