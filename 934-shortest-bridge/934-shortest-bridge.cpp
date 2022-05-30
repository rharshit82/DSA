class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        bool flag=false;
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    floodfill(grid,i,j,q);
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        int res=0;
        int dir[] = {1, 0, -1, 0, 1};
        while(!q.empty()){
            int k=q.size();
                        // cout<<k<<endl;

            while(k--){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for(int i=0; i<4; i++){
                    int nr = r+ dir[i];
                    int nc = c+ dir[i+1];
                    if(nr<0 or nc<0 or nr>=n or nc>=m or grid[nr][nc]==-1) continue;
                    // cout<<nr<<" "<<nc<<endl;
                    if(grid[nr][nc]==1) return res;
                    q.push({nr,nc});
                    grid[nr][nc]=-1;
                    
                }
            }
            res++;
        }
        return -1;
    }
    void floodfill(vector<vector<int>>& grid, int i, int j, queue<pair<int,int>>& q){
        int n=grid.size();
        int m=grid[0].size();
        if(i>=n or i<0 or j>=m or j<0 or grid[i][j]!=1) return;
        grid[i][j]=-1;
        q.push({i,j});
        floodfill(grid,i+1,j,q);
        floodfill(grid,i-1,j,q);
        floodfill(grid,i,j+1,q);
        floodfill(grid,i,j-1,q);
    }
};