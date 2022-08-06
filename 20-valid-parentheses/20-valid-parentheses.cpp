class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char> st;
        for(int i=0; i<n; i++){
            cout<<s[i];
            if(s[i] == '(' or s[i]=='[' or s[i]=='{') st.push(s[i]);
            if(s[i] == ')'){
                if(st.empty() or st.top()!='(') return false;
                st.pop();
            }
            if(s[i] == ']'){
                if(st.empty() or st.top()!='[') return false;
                st.pop();
            }
            if(s[i] == '}'){
                if(st.empty() or st.top()!='{') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};