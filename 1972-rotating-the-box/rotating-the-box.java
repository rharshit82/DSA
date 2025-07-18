class Solution {
    public char[][] rotateTheBox(char[][] boxGrid) {
        int n = boxGrid.length;
        int m = boxGrid[0].length;

        char[][] result = new char[m][n];

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                result[i][j] = boxGrid[n - 1 - j][i];
            }
        }
        

        for(int j=0; j<n; j++){
            int i = m-1;
            while(i>=0){
                if(result[i][j] == '.'){
                    int k = i;
                    while(k>=0 && result[k][j]!='*' && result[k][j]!='#') k--;
                    if(k>=0 && result[k][j] == '#'){
                        result[i][j] = '#';
                        result[k][j] = '.';
                    }
                }
                i--;
            }
        }
        return result;
        
    }
}