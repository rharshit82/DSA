class Solution {
public:
    
    int dfs(int i, int j, vector<vector<int>>&  grid){
        cout<<i<<" "<<j<<endl;
        if(i>=grid.size() or j>=grid[0].size() or i<0 or j<0 or grid[i][j]!=1) return 0;
        grid[i][j]=0;
        return 1+ dfs(i+1,j,grid)+ dfs(i,j+1,grid) + dfs(i-1,j,grid)+   dfs(i,j-1,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0; i<grid.size();i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    res = max(res, dfs(i,j,grid));
                }
                    
            }
        }
        return res;
    }
};