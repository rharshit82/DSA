class Solution {
public:
    bool dfs(int i, int j, int index, string word,vector<vector<char>>& board){
        if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or board[i][j]!=word[index]) return false;
        if(index==word.size()-1 and board[i][j]==word[index]) return true;
        int temp = board[i][j];
        board[i][j]='*';
        bool res= dfs(i+1,j,index+1,word,board) or dfs(i,j+1,index+1,word,board)
            or dfs(i-1,j,index+1,word,board) or dfs(i,j-1,index+1,word,board);
        board[i][j]=temp;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dfs(i,j,0,word,board)) return true;
            }
        }
        return false;
    }
};