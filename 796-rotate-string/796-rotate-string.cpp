class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal) return true;
        int n=s.size();
        for(int i=0; i<n; i++){
            s= s[n-1]+ s;
            s.pop_back();
            if(s==goal) return true;
        }
        return false;
    }
};