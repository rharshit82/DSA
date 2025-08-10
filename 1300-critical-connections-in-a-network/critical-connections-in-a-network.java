class Solution {
    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        // find bridges in the graph
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<n; i++) adj.add(new ArrayList<>());
        for(List<Integer> edge : connections){
            int u = edge.get(0);
            int v = edge.get(1);
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        // low, disc for each node. if (discovert time of a node is A and lowest time that it can reach by adjacent is B, If A < B, it is a bridge)

        List<List<Integer>> res = new ArrayList<>();
        int[] low = new int[n];
        int[] disc = new int[n];
        int[] time = new int[1];
        time[0] = 0;
        boolean[] visited = new boolean[n];
        Arrays.fill(visited, false);
        dfs(0,  -1, adj, n, low, disc,time, visited,res);
        return res;
    }

    void dfs(int u, int p, List<List<Integer>> adj, int n, int[] low, int[] disc, int[] time, boolean[] visited, List<List<Integer>> res){
        disc[u] = time[0]++;
        low[u] = disc[u];
        visited[u] = true;

        for(int v : adj.get(u)){
            if(v == p) continue;
            if(!visited[v]){
                dfs(v, u, adj, n, low, disc, time, visited, res);
                low[u] = Math.min(low[u], low[v]);

                if(low[v] > disc[u]){
                    List<Integer> curr = new ArrayList<>();
                    curr.add(u);
                    curr.add(v);
                    res.add(curr);
                }
            } else {
                low[u] = Math.min(low[u], low[v]);
            }
        }
    }
}