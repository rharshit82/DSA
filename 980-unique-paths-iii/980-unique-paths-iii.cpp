class Solution {
public:
    int count = 0;
    int traverse(int i, int j, vector<vector<int>>& grid, int empty){
        int n= grid.size();
        int m= grid[0].size();
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j] == -1) return 0;
        if(grid[i][j]==0) empty++;
        if(grid[i][j] == 2) {
            return empty == count;
        }
        grid[i][j] = -1;
        int res=traverse(i+1,j,grid, empty) + traverse(i-1,j,grid, empty) + traverse(i,j+1,grid, empty)+ traverse(i,j-1,grid, empty);
        grid[i][j] = 0;
        return res;
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int start_x = 0, start_y = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    start_x = i;
                    start_y = j;
                } else if(grid[i][j] == 0){
                    count++;
                }
            }
        }
        return traverse(start_x, start_y, grid, 0);
    }
};