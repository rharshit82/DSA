class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        map<int, vector<int>> mp;
        for(int i=0; i<n; i++){
            if(manager[i]!=-1)
                mp[manager[i]].push_back(i);
        }
        return dfs(informTime,headID, mp);
    }
    int dfs(vector<int>& informTime, int headID, map<int, vector<int>> &mp){
        if(mp[headID].size()==0) return 0;
        int mx=0;
        for(auto i: mp[headID]){
            mx=max(mx, dfs(informTime, i, mp ));
        }
        return informTime[headID] + mx;
    }
};