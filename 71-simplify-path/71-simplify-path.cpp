class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size();
        stack<string> st;
        int i=0;
        for(int i=0; i<n; i++){
            if(path[i]=='/') continue;
            string s="";
            while(path[i]!='/' and i<n){
                s+=path[i];
                i++;
            }
            if(s == ".")
                continue;
            else if(s == "..")
            {
                if(!st.empty())
                    st.pop();
            }
            else
                st.push(s);
        }
        string res="";
        while(!st.empty()){
            res='/'+st.top()+res;
            st.pop();
        }
        if(res.size()==0){
            return "/";
        }
        return res;
    }
};