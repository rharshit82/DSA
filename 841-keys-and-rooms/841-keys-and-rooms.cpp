class Solution {
public:
    vector<bool> visited;
    void dfs(vector<vector<int>>& rooms, int room ){
        if(room>=rooms.size() or room<0 or visited[room]) return;
        visited[room]=true;
        for(auto i: rooms[room])
            dfs(rooms,i);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        visited.resize(n,false);
        dfs(rooms,0);
        for(int i=0;i<n;i++){
            if(visited[i]==false) return false;
        }
        return true;
    }
};