class Solution {
public:
    bool dfs(vector<vector<int>> &graph, int i, vector<int>&visited){
        if(visited[i]==2) return true;
        visited[i]=2;
        for(auto node: graph[i]){
            if(visited[node]!=1)
                if(dfs(graph,node,visited)) return true;
        }
        visited[i]=1;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> visited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(graph,i,visited)) return false;
            }
        }
        return true;
    }
};