class Solution {
    public int totalNQueens(int n) {
        List<String> board = new ArrayList<>();
        
        for(int i=0; i<n; i++){
            String row = ".".repeat(n);
            board.add(row);
        }

        return backtrack(board, 0, n);
    }

    int backtrack(List<String> board, int col, int n){
        if(col == n){
            return 1;
        }
        int ways = 0;
        for(int row = 0; row<n; row++){
            if(isSafe(row, col, board)){
                char[] r = board.get(row).toCharArray();
                r[col] = 'Q';
                board.set(row, new String(r));
                ways += backtrack(board, col+1, n);
                r[col] = '.';
                board.set(row, new String(r));
            }
        }
        return ways;
    }
    boolean isSafe(int row, int col, List<String> board){
        for(int i=0; i<col; i++){
            if(board.get(row).charAt(i) == 'Q') return false;
        }
        for(int i=row, j = col; i>=0 && j >=0 ; i--, j--){
            if(board.get(i).charAt(j) == 'Q') return false;
        }
        for(int i=row, j = col; i<board.size() && j >=0; i++, j--){
            if(board.get(i).charAt(j) == 'Q') return false;
        }
        return true;
    }
}