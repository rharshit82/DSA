class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string sn="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' ' and sn.size()==0)  continue;
            if(s[i]!=' '){
                sn+=s[i];
            }
            else{
                st.push(sn);
                sn.clear();
            }
        }
        if(sn.size()>0) st.push(sn);
        string res="";
        while(!st.empty()){
            res+=st.top()+' ';
            st.pop();
        }
        res.pop_back();
        return res;
    }
};