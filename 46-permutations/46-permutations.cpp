class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>&temp, vector<int>&nums, vector<bool>&visited, int i){
        if(temp.size()==nums.size()){
            res.push_back(temp);
            return;
        } 
        for(int j=0; j<nums.size(); j++){
            if(!visited[j]){
                temp.push_back(nums[j]);
                visited[j]=true;
                backtrack(res,temp,nums,visited,j);
                visited[j]=false;
                temp.pop_back();
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> visited(n,false);
        backtrack(res,temp,nums,visited,0);
        return res;
    }
};