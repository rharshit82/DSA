class Solution {
    public int countCompleteComponents(int n, int[][] edges) {
        int res = 0;
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<n; i++) adj.add(new ArrayList<>());
        for(int i=0; i<edges.length; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        boolean[] visited = new boolean[n];
        for(int i=0; i<n; i++) visited[i] = false;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                int[] r = dfs(i, adj, visited);
                int edgeSum = r[1];

                int edgesCount = edgeSum / 2;
                int verticeCount = r[0];
                if((verticeCount * (verticeCount - 1) / 2) == edgesCount) res++;
            }
        }
        return res;
    }
   
    
    int[] dfs(int u, List<List<Integer>> adj, boolean[] visited){
        visited[u] = true;
        int vertices = 1;
        int edgeCount = adj.get(u).size();
        for(int neigh : adj.get(u)){
            if(!visited[neigh]){
                int[] sub = dfs(neigh, adj, visited);
                vertices+= sub[0];
                edgeCount+= sub[1];
            }
        }
        return new int[]{vertices, edgeCount};
    }
}