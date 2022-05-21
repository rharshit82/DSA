class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        int n=s.size();
        for(int i=0; i<n; i++){
            if(st.empty() or st.top().first!=s[i]){
                st.push({s[i],1});
            } else if(st.top().first==s[i]){
                st.push({s[i],st.top().second+1});
            }
            if(st.top().second==k){
                for(int i=0; i<k; i++) st.pop();
            }
        }
        string res="";
        while(!st.empty()){
            res+=st.top().first;
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};