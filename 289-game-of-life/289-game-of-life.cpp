class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        int dx[] = {1,-1,0,0,1,-1,1,-1};
        int dy[] = {0,0,1,-1,1,-1,-1,1};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int count=0;
                for(int k=0; k<8; k++){
                    int nr = i+dx[k];
                    int nc = j+dy[k];
                    if(nr<0 or nr>=n or nc<0 or nc>=m) continue;
                    if(abs(board[nr][nc])==1) count++;
                }
                if(abs(board[i][j]) and (count!=2 and count!=3)) board[i][j]=-1;
                if(board[i][j]==0 and count==3) board[i][j]=2;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==-1) board[i][j]=0;
                if(board[i][j]==2) board[i][j]=1;
            }
        }
    }
};