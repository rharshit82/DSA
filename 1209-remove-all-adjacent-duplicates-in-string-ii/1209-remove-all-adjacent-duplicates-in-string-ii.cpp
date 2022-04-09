class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(int i = 0; i < s.length(); i++)
        {
            if(st.empty() || st.top().first != s[i])
                st.push({s[i], 1});
            else if(st.top().first == s[i])
            {
                auto it = st.top();
                st.pop();
                st.push({s[i], it.second + 1});
            }
            if(st.top().second == k)
                st.pop();
        }
        string ans;
        while(st.size())
        {
            ans += string(st.top().second, st.top().first);
            st.pop();
        }
        if(ans.size())
            reverse(ans.begin(), ans.end());
        return ans;
    }
};