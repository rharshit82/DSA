class Solution {
public:
    
    int numOfMinutes(int n, int headId, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<(int)manager.size();i++){
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        }
        return dfs(headId,informTime,adj);
    }
    int dfs(int headId, vector<int>&informTime,unordered_map<int,vector<int>> &adj){
        int mx=0;
        for(auto i: adj[headId]){
            mx=max(mx,dfs(i,informTime,adj));
        }
        return informTime[headId]+mx;
    }
};