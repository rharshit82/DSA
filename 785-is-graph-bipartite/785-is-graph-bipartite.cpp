class Solution {
public:
    bool dfs(int V, vector<int>& col, int c, vector<vector<int>>&graph){
        if(col[V]==-1) col[V]= c;
        for(auto node: graph[V]){
            if(col[node] == -1){
                if(!dfs(node,col,!c,graph)) return false;
            }
            else if(col[node]==col[V]) return false;
            
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> col(n+1,-1);
        for(int i=0; i<n; i++){
            if(col[i] == -1){
                if(!dfs(i,col, 1, graph)) return false;
            }
        }
        return true;
    }
};