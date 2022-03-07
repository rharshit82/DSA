class Solution {
public:
    vector<bool> visited;
    void dfs(int i, vector<vector<int>> &graph){
        visited[i]=true;
        for(auto edge: graph[i]){
            if(!visited[edge]) 
                dfs(edge,graph);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        visited.resize(n,false);
        vector<vector<int>> graph(n);
        for(int i=0;i<connections.size();i++){
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,graph);
                res++;
            }
        }
        return res-1;
    }
};