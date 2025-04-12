class Solution {
    public int minOperations(int[][] grid, int x) {
        int n = grid.length;
        int m = grid[0].length;
        int[] sortedArray = new int[m*n];
        int k = 0;
        
        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]%x!=grid[0][0]%x) return -1;
                sortedArray[k++] = grid[i][j];
            }
        }

         Arrays.sort(sortedArray);
        int median = sortedArray[(n * m) / 2];

        int operations = 0;
        for (int val : sortedArray) {
            operations += Math.abs(val - median) / x;
        }

        return operations;
    }
}