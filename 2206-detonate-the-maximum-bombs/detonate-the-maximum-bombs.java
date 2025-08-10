class Solution {
    public int maximumDetonation(int[][] bombs) {
        int n = bombs.length;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 0; i < n; i++) {
            long x1 = bombs[i][0];
            long y1 = bombs[i][1];
            long r1 = bombs[i][2];

            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                long x2 = bombs[j][0];
                long y2 = bombs[j][1];
                long r2 = bombs[j][2];
                long dx = x2 - x1;
                long dy = y2 - y1;
                if (dx * dx + dy*dy <= r1 * r1) {
                    adj.get(i).add(j);
                }
            }
        }
        int res = 0;
        for(int i=0; i<n; i++){
            boolean[] visited = new boolean[n];
            visited[i] = true;
            int bombsBlasted = dfs(i, adj, visited);
            res = Math.max(res, bombsBlasted);
        }
        return res;
    }
    int dfs(int node, List<List<Integer>> adj, boolean[] visited){
        
        int bombs = 1;
        for(int neigh : adj.get(node)){
            if(!visited[neigh]){
                visited[neigh] = true;
                bombs += dfs(neigh, adj, visited);
            }
        }
        return bombs;

    }
}