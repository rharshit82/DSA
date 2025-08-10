class Solution {
    class Node {
        int mask, curr, steps;

        public Node(int curr, int mask, int steps) {
            this.curr = curr;
            this.mask = mask;
            this.steps = steps;
        }
    }

    public int shortestPathLength(int[][] graph) {
        int n = graph.length;
        Queue<Node> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            q.offer(new Node(i, 1 << i, 0));
        }
        int targetMask = (1<<n) - 1;
        boolean[][] visited = new boolean[n][1<<n];
        while (!q.isEmpty()) {
            Node curr = q.poll();
            int mask = curr.mask;
            if(mask == targetMask) return curr.steps;
            for (int neigh : graph[curr.curr]) {
                if(!visited[neigh][mask | (1<<neigh)]){
                    q.offer(new Node(neigh, mask | (1<<neigh), curr.steps + 1));
                    visited[neigh][mask | (1<<neigh)] = true;
                }
                    
            }
        }
        return 0;

    }
}