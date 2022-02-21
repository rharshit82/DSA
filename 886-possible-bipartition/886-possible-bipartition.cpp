class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        queue<int> q;
        vector<int> color(n+1,0);
        vector<vector<int>> graph(n+1);
        for(auto i: dislikes){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        for(int i=1;i<=n;i++){
            if(color[i]) continue;
            color[i]=1;
            q.push(i);
            while(!q.empty()){
                auto cur=q.front(); q.pop();
                for(auto node: graph[cur]){
                    if(!color[node]){
                        color[node]=-color[cur];
                        q.push(node);
                    }
                    else if(color[node]==color[cur]) return false;
                }
            }
        }
        return true;
    }
};