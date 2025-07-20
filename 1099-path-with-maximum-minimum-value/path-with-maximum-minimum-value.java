class Solution {
    public int maximumMinimumPath(int[][] grid) {
        int n=grid.length, m = grid[0].length;
        PriorityQueue<int[]> q = new PriorityQueue<>((a, b)-> {
            return b[0] - a[0];
        });

        boolean[][] visited = new boolean[n][m];
        for(boolean[] arr : visited){
            Arrays.fill(arr, false);
        }

        q.offer(new int[]{grid[0][0], 0, 0});

        int res = 0;

        while(!q.isEmpty()){
            int[] curr = q.poll();
            int minSoFar = curr[0];
            int x = curr[1];
            int y = curr[2];
            if(x == n-1 && y == m-1) return minSoFar;
            int[][] dirs = {{ 1, 0}, {0, 1}, {-1, 0}, {0, -1}};

            for(int i=0; i<4; i++){
                int dx = x + dirs[i][0];
                int dy = y + dirs[i][1];

                if(dx >= 0 && dx <n && dy >= 0 && dy < m && !visited[dx][dy]){
                    q.offer(new int[]{Math.min(grid[dx][dy], minSoFar), dx, dy});
                    visited[dx][dy] = true;
                }
            }
        }
        return -1;
    }
}