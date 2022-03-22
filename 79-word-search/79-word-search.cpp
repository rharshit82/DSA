class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int k){
        if(i>=board.size() or i<0 or j>=board[0].size() or j<0 or word[k]!=board[i][j]) return false;
        if(k==word.size()-1) return true;
        char temp = board[i][j];
        board[i][j]='*';
        if(dfs(board,i+1,j,word,k+1) or dfs(board,i-1,j,word,k+1) or dfs(board,i,j+1,word,k+1) or dfs(board,i,j-1,word,k+1)){
            return true;
        }
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(dfs(board,i,j,word,0))
                    return true;
            }
        }
        
        return false;
    }
};