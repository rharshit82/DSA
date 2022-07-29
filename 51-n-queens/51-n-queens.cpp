class Solution {
public:
    bool isSafe(vector<string>&board,int row, int col){
        int n=board.size();
        for(int i=0; i<=col-1; i++){
            if(board[row][i] == 'Q') return false;
        }
        for(int i=row-1, j= col-1; i>=0 and j>=0; i--, j--){
            if(board[i][j] == 'Q') return false;
        }
         for(int i=row+1, j = col-1; i<n and j>=0; i++, j--){
            if(board[i][j] == 'Q') return false;
        }
        return true;
        
    }
    void backtrack(vector<string>&board, vector<vector<string>>&res, int col){
        int n=board.size();
        if(col==n){
            res.push_back(board);
        }
        for(int row = 0; row<n; row++){
            if(isSafe(board,row,col)){
                board[row][col] = 'Q';
                backtrack(board,res,col+1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string s(n, '.');
        vector<string> board;
        for(int i=0; i<n; i++) board.push_back(s);
        backtrack(board,res,0);
        return res;
    }
};