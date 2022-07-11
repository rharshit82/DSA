class Solution {
public:
    
    void backtrack(vector<int>&nums,vector<vector<int>>&res, int i, vector<int>&temp){
        if(i>=nums.size()) return;
        temp.push_back(nums[i]);
        res.push_back(temp);
        backtrack(nums,res,i+1,temp);
        temp.pop_back();
        backtrack(nums,res,i+1,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        vector<int> temp;
        backtrack(nums,res,0,temp);
        return res;
    }
};