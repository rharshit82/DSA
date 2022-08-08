class Solution {
public:
    string largestOddNumber(string s) {
        string res = "";
        int n=s.size();
        bool f=false;
        for(int i=n-1; i>=0; i--){
            if((s[i]-'0')%2!=0){
                f=true;
            }
            if(f){
                res.push_back(s[i]);
            }
        }
        reverse(res.begin(), res.end());
        if(res.size()!=1) return res;
        for(int i=0; i<n; i++){
            if((s[i]-'0')%2!=0)
            res[0] = max(res[0], s[i]);
        }
        return res;
    }
};