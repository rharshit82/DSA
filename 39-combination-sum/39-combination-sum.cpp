class Solution {
public:
    vector<vector<int>> ans;
    void combination(vector<int>&res, int target, int i, vector<int>& candidates){
        if(i==candidates.size()){
             if(target==0){
            ans.push_back(res);
             }
            return;
        } 
        if(candidates[i]<=target){
            res.push_back(candidates[i]);
            combination(res,target-candidates[i],i,candidates);
            res.pop_back();
        }
        combination(res,target,i+1,candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        combination(temp, target, 0,candidates);
        return ans;
    }
};