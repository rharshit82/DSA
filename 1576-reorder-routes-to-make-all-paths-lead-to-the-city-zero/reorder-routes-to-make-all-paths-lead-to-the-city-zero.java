class Solution {
    public int minReorder(int n, int[][] connections) {
        int res = 0;
        List<int[]>[] graph = new ArrayList[n];
        for(int i=0; i<n; i++) graph[i] = new ArrayList<>();
        for(int[] conn : connections){
            int u = conn[0];
            int v = conn[1];
            graph[u].add(new int[]{v, 1});
            graph[v].add(new int[]{u, 0});
        }

        Queue<Integer> q = new LinkedList<>();
        q.offer(0);
        Set<Integer> visited = new HashSet<>();

        while(!q.isEmpty()){
            int curr = q.poll();
            if(visited.contains(curr)) continue;
            visited.add(curr);

            for(int[] neigh : graph[curr]){
                
                int neighNode = neigh[0];
                int dir = neigh[1];
                if(visited.contains(neighNode)) continue;
                res+= dir;
                q.offer(neighNode);
            }
        }
        return res;
    }
}