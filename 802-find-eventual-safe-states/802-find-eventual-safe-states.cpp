 class Solution {
 	bool dfs(vector<vector<int>>& graph, int v, vector<int>& dp) {

 		if (dp[v])
 			return dp[v] == 1;

 		dp[v] = -1;

 		for (auto it = graph[v].begin(); it != graph[v].end(); it++)
 			if (!dfs(graph, *it, dp))
 				return false;

 		dp[v] = 1;

 		return true;
 	}
 public:
 	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

 		int V = graph.size();

 		vector<int>res;
 		vector<int>dp(V, 0);

 		for (int i = 0; i < V; i++) {    
 			if (dfs(graph, i, dp))
 				res.push_back(i);
 		}

 		return res;
 	}
 };