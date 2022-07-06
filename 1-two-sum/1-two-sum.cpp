class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(target-nums[i])!=mp.end()){
                vector<int> temp = {i,mp[target-nums[i]]};
                return temp;
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};