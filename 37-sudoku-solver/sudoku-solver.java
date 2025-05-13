class Solution {
    public void solveSudoku(char[][] board) {
        solve(board);
    }

    boolean solve(char[][] board){
        int n = 9;

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.'){
                    for(char ch = '1'; ch<='9'; ch++){
                        if(isValid(board, i, j, ch)){
                            board[i][j] = ch;
                            if(solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    boolean isValid(char[][] board, int i, int j, char ch){
        int n = board.length;
        int m = board[0].length;
        for(int k=0; k<9; k++){
            if(board[k][j] == ch) return false; 
            if(board[i][k] == ch) return false; 
            int blockRow = (i/3)*3 + k/3;
            int blockCol = (j/3)*3 + k%3;
            if(board[blockRow][blockCol] == ch) return false; 
        }
        return true;
    }
}