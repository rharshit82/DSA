class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int open = 0, close = 0;
        int res = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '(') open++;
            if(s[i] == ')') close++;
            if(open == close){
                res = max(res, open+close);
            }
            if(close>open){
                open = close = 0;
            }
        }
        open = close = 0;
        for(int i=n-1; i>=0; i--){
            if(s[i] == '(') open++;
            if(s[i] == ')') close++;
            if(open == close){
                res = max(res, open+close);
            }
            if(close<open){
                open = close = 0;
            }
        }
        return res;
    }
};