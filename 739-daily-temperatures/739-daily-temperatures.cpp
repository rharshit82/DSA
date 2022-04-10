class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        int n=temperatures.size();
        vector<int> res(n,0);
        st.push({temperatures[n-1],n-1});
        for(int i=n-2; i>=0; i--){
            while(!st.empty() and st.top().first<=temperatures[i]){
                st.pop();
            }
            if(!st.empty() and st.top().first>=temperatures[i])
                res[i]=st.top().second- i;
            else res[i]=0;
            st.push({temperatures[i],i});
        }
        return res;
    }
};