class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int r=0,c=0;
        for(int i=1;i<n;i++){
            if(matrix[i][0]>matrix[r][c]){
                c=i;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(j-1>=0 and j+1<n){
                    matrix[i][j]=min(matrix[i-1][j-1],min(matrix[i-1][j],matrix[i-1][j+1]))+matrix[i][j];
                } else if(j+1<n){
                    matrix[i][j]=min(matrix[i-1][j],matrix[i-1][j+1])+matrix[i][j];
                } else if(j-1>=0){
                    matrix[i][j]=min(matrix[i-1][j-1],matrix[i-1][j])+matrix[i][j];
                }
            }
        }
        return *min_element(matrix[m-1].begin(),matrix[m-1].end());
    }
};