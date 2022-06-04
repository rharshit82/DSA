class Solution {
public:
    bool isSafe(int row, int col, vector<string>&board, int n){
        for(int i=col-1; i>=0; i--){
            if(board[row][i]=='Q') return false;
        }
        for(int i=row-1,j=col-1; i>=0 and j>=0; i--,j--){
            if(board[i][j]=='Q') return false;
        }
        for(int i=row+1,j=col-1; i<n and j>=0; i++,j--){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
    
    void backtrack(int col, vector<string>&board, vector<vector<string>>&res, int n){
        if(col==n) {
            res.push_back(board);
            return;
        }
        for(int row=0; row<n; row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                backtrack(col+1,board,res,n);
                board[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board;
        string s(n,'.');
        for(int i=0; i<n; i++){
            board.push_back(s);
        }
        backtrack(0,board,res,n);
        return res;
    }
};