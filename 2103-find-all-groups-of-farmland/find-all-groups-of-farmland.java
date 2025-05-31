class Solution {
    public int[][] findFarmland(int[][] land) {
        List<int[]> res = new ArrayList<>();
        int n = land.length, m = land[0].length;
        
        for(int i = 0; i<n; i++){
            for(int j=0; j<m; j++){
                if(land[i][j] == 1 && (i-1 < 0 || land[i-1][j] == 0) && (j-1 < 0 || land[i][j-1] == 0)){
                    int u1 = i, v1 = j;
                    int u2 = i, v2 = j;
                    while(u2 + 1 < n && land[u2+1][v2] != 0){
                        u2++;
                    }
                    while(v2 + 1 < m && land[u2][v2+1] != 0){
                        v2++;
                    }
                    res.add(new int[]{u1, v1, u2, v2});
                }
            }
        }
        int[][] arr = new int[res.size()][4];
        for(int i=0; i<res.size(); i++){
            arr[i] = res.get(i);
        }
        return arr;
    }
}