class Solution {
    class Pair{
        int time, x, y;
        public Pair(int time, int x, int y){
            this.time =time;
            this.x = x;
            this.y = y;
        }
    }
    public int swimInWater(int[][] grid) {
        List<List<Integer>> graph = new ArrayList<>();
        PriorityQueue<Pair> pq = new PriorityQueue<>((a,b) -> a.time - b.time);

        int n = grid.length, m = grid[0].length;

        boolean[][] visited = new boolean[n+1][m+1];
        for(boolean[] row : visited){
            Arrays.fill(row, false);
        }
        int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        pq.offer(new Pair(grid[0][0], 0, 0));

        while(!pq.isEmpty()){
            Pair curr = pq.poll();
            int t = curr.time;
            int x = curr.x;
            int y = curr.y; 
            if(x == n-1 && y == m-1) return t;
            for(int i=0; i<4; i++){
                int nr = x + dirs[i][0];
                int nc = y + dirs[i][1];
                if(nr < 0 || nr >=n || nc < 0 || nc >=m) continue;
                if(visited[nr][nc] == false){
                    visited[nr][nc] = true;
                    int time = Math.max(t, grid[nr][nc]);
                    pq.offer(new Pair(time, nr, nc));
                }
            }
        }
        return -1;

    }
}