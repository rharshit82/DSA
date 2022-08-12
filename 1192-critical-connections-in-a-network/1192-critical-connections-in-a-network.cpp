class Solution {
public:
    void dfs(int node, int P, vector<int>&tim, vector<int>&low, vector<bool>&vis, vector<vector<int>>&res,  int &timer, vector<vector<int>>&g){
        vis[node]=true;
        tim[node] = low[node] = timer++;
        for(auto it: g[node]){
            if(it == P) continue;
            if(!vis[it]){
                dfs(it, node, tim, low, vis, res, timer,g);
                low[node] = min(low[node], low[it]);
                if(low[it] > tim[node]){
                    vector<int> temp;
                    temp.push_back(node);
                    temp.push_back(it);
                    res.push_back(temp);
                }
            } else{
                low[node] = min(low[node], tim[it]);
            }
             
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {
        vector<int> tim(n, -1);
        vector<int> low(n, -1);
        vector<vector<int>> res;
        vector<bool> vis(n, false);
        int timer = 0;
        vector<vector<int>> g(n);
        for(auto e: conn){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, -1, tim, low, vis, res, timer, g);
            }
        }
        return res;
    }
};