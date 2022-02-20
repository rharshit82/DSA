class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int tot=0;
        int dir[]={0,1,0,-1,0};
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0) tot++;
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        int res=0;
        int cnt=0;
        while(!q.empty()){
            int k=q.size();
            cnt+=k;
            while(k--){
                auto [r,c]=q.front(); q.pop();
                for(int i=0;i<4;i++){
                    int nr=dir[i]+r;
                    int nc=dir[i+1]+c;
                    if(nr<0 or nc<0 or nr>=m or nc>=n or grid[nr][nc]!=1) continue;
                    grid[nr][nc]=2;
                    q.push({nr,nc});
            }
            }
            if(!q.empty()) res++;
        }
        return tot==cnt?res:-1;
    }
};