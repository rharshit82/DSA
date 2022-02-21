class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,0);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(color[i]) continue;
            color[i]=1;
            q.push(i);
            while(!q.empty()){
                int cur=q.front(); q.pop();
                for(auto node: graph[cur]){
                    if(!color[node]){
                        color[node]=-color[cur];
                        q.push(node);
                    }
                    else{
                        if(color[node]==color[cur]) return false;
                    }
                }
            }
        }
        return true;
    }
};