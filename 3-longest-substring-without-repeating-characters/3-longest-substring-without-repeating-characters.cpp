class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int j=0;
        int i=0;
        set<char>st;
        int res=0;
        while(j<n){
            // cout<<j<<" "<<i<<endl;
            if(st.find(s[j])==st.end()){
                st.insert(s[j]);
                res=max(res, j-i+1);
                j++;
            } else{
                while(st.find(s[j])!=st.end() and i<n){
                    st.erase(s[i]);
                    i++;
                }
            }
        }
        return res;
    }
};