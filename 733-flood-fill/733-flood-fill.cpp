class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>> q;
        int oldColor = image[sr][sc];
        if(oldColor == newColor) return image;
        q.push({sr,sc});
        int dir[] = {-1,0,1,0,-1};
        image[sr][sc]=newColor;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nr = r+dir[i];
                int nc = c+dir[i+1];
                if(nr<0 or nc<0 or nr>=n or nc>=m or image[nr][nc]!=oldColor) continue;
                image[nr][nc] = newColor;
                q.push({nr,nc});
            }
        }
        return image;
    }
};