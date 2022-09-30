class Solution {
public:
    static bool customSort(vector<int> &a,  vector<int>& b){
        if(a[0] == b[0])
            return a[1]<b[1];
            
        return a[0] > b[0];
        
    }
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        int n = p.size();
        sort(p.begin(), p.end(), customSort);
        int maxx=INT_MIN, count=0;
        for(auto pp : p){
            if(pp[1]<maxx)  count++;
            else    maxx=pp[1];
        }
        
        return count;
    }
};