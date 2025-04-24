class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if(oldColor == newColor) return image;


        Queue<int[]> q = new LinkedList<>();

        q.add(new int[]{sr, sc});
        int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.isEmpty()){
            int[] curr = q.poll();
            int r = curr[0];
            int c = curr[1];

            image[r][c] = newColor;
            for(int i=0; i<4; i++){
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if(nr < 0 || nr >=image.length || nc < 0 || nc >= image[0].length || image[nr][nc]!=oldColor) continue;
                q.add(new int[]{nr, nc});
            }
        }
        return image;
    }
}