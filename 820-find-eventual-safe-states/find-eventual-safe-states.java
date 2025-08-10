class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        int n = graph.length;
        int[] state = new int[n];
        // 0 -> unvisited, 1 -> visiting, 2 -> safe
        List<Integer> res = new ArrayList<>();
        for(int i=0; i<n; i++){
            if(state[i] == 0)
                dfs(graph, state, i, res);
        }

        for(int i=0; i<n; i++) if(state[i] ==2) res.add(i);
        return res;
    }

    boolean dfs(int[][] graph, int[] state, int node, List<Integer> res){
        if(state[node] ==1) return false;
        if(state[node] == 2) return true;
        state[node] = 1;

        for(int neigh : graph[node]){
            if(state[neigh] == 1 || !dfs(graph, state, neigh, res)){
                return false;
            }
        }

        state[node] = 2;
        return true;
    }
}