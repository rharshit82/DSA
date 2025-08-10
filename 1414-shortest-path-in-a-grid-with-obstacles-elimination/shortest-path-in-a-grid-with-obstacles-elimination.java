class Solution {
    class Node {
        int  x, y, steps, obs;
        public Node(int x, int y, int steps, int obs){
            this.x = x;
            this.y = y;
            this.steps = steps;
            this.obs = obs;
        }
    }
    public int shortestPath(int[][] grid, int k) {
        int n = grid.length;
        int m = grid[0].length;
        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(0, 0, 0, grid[0][0] == 1 ? 1 : 0));
        int[][] dirs = new int[][]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        boolean[][][] visited = new boolean[n][m][k + 1];
        while(!q.isEmpty()){
            Node curr = q.poll();

            if(curr.x == n-1 && curr.y == m-1 && curr.obs <= k) return curr.steps;
            for(int i=0; i<4; i++){
                int dx = curr.x + dirs[i][0];
                int dy = curr.y + dirs[i][1];
                

                if(dy >= 0 && dy <=m-1 && dx>=0 && dx<=n-1 ){
                    int isObstacle = grid[dx][dy] == 1 ? 1 : 0;
                    if(curr.obs + isObstacle >k) continue;
                    if(visited[dx][dy][curr.obs + isObstacle]) continue;
                    visited[dx][dy][curr.obs + isObstacle] = true;
                    q.offer(new Node(dx, dy, curr.steps + 1, curr.obs + isObstacle));
                }
            }
        }

        return -1;
    }
}