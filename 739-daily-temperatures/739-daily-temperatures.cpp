class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        stack<pair<int,int>> st;
        int n=arr.size();
        vector<int> res(n);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() and st.top().first<=arr[i]) st.pop();
            if(st.empty()){
                res[i]=0;
            } else{
                res[i]=st.top().second-i;
            }
            st.push({arr[i],i});
        }
        return res;
    }
};