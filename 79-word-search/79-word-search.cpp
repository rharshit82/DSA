class Solution {
public:
    bool dfs(int i,int j, vector<vector<char>>& board,string &word,int n,int m, int k){
        if(i>=n or j>=m or i<0 or j<0) return false;
        if(k==word.size()-1 and word[k]==board[i][j])return true;
        if(board[i][j]!=word[k]) return false;
        char temp = board[i][j];
        board[i][j]='*';
        bool res= dfs(i+1,j,board,word,n,m,k+1) or dfs(i,j+1,board,word,n,m,k+1)
            or dfs(i-1,j,board,word,n,m,k+1) or dfs(i,j-1,board,word,n,m,k+1);
        board[i][j]=temp;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        bool flag=false;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(word[0]==board[i][j]){
                    if(dfs(i,j,board,word,n,m,0)) flag=true;
                }
            }
        }
        return flag;
    }
};