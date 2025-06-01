class Solution {
    public int countServers(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int[] row = new int[n];
        int[] col = new int[m];
        Arrays.fill(row, 0);
        Arrays.fill(col, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                row[i]+= grid[i][j] == 1?1 : 0;
                col[j]+= grid[i][j] == 1 ? 1 : 0;
            }
        }
        int res = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && (row[i] > 1 || col[j] > 1)) res++;
            }
        }
        return res;
    }
}