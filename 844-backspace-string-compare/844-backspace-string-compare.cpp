class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss,ts;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='#' && !ss.empty()) ss.pop();
            else if(s[i]!='#') ss.push(s[i]);
        }
        for(int i=0; i<t.size(); i++){
            if(t[i]=='#' && !ts.empty()) ts.pop();
            else if(t[i]!='#') ts.push(t[i]);
        }
        while(!ss.empty() or !ts.empty()){
            if(ss.empty() && !ts.empty())  return false;
            if(!ss.empty() && ts.empty()) return false;
            if(ss.top()!=ts.top()) return false;
            
            ss.pop();
            ts.pop();
        }
        return true;
    }
};