class Solution {
public:
    bool isSafe(int i, int j, int R, int C){
        if(i>=0 and i<R and j>=0 and j<C) return true;
        return false;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int R = board.size();
        int C = board[0].size();
        int dx[] = {1,-1,0,0,1,-1,1,-1};
        int dy[] = {0,0,1,-1,1,-1,-1,1};
        for(int i=0; i<R;i++){
            for(int j=0;j<C; j++){
                int count=0;
                for(int k=0; k<8; k++){
                    if(isSafe(i+dx[k], j+ dy[k], R, C) && abs(board[i+dx[k]][j+dy[k]])==1) count++;
                }
                if(abs(board[i][j])==1 && (count!=2 && count!=3)) board[i][j]=-1;
                if(board[i][j]==0 && count==3) board[i][j]=2;
            }
        }
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(board[i][j]==-1) board[i][j]=0;
                if(board[i][j]==2) board[i][j]=1;
            }
        }
    }
};