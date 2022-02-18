class Solution {
public:
    vector<int> parents;
    int find(int x){
        return parents[x]==x? x: find(parents[x]);
    }
    bool equationsPossible(vector<string>& equations) {
        parents.resize(26,0);
        for(int i=0;i<25;i++) parents[i]=i;
        for(auto s: equations){
            if(s[1]=='='){
                int x=find(s[0]-'a');
                int y=find(s[3]-'a');
                parents[y]=x;
            }
        }
        for(auto s: equations){
            if(s[1]=='!'){
                int x=find(s[0]-'a');
                int y=find(s[3]-'a');
                if(x==y) return false;
            }
        }
        return true;
    }
};