class Solution {
public:
    void generate(vector<string>&res, int open, int close, string s,int n){
        if(s.size()==2*n){
            res.push_back(s);
            return;
        }
        if(open<n){
            generate(res,open+1,close,s+'(',n);
        }
        if(close<open){
            generate(res,open,close+1,s+')',n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s="";
        generate(res,0,0,s,n);
        return res;
    }
};