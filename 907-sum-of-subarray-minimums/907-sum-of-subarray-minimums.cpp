#define MOD 1000000007
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n= arr.size();
        vector<int> next(n);
        vector<int> prev(n);
        stack<pair<int,int>> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() and st.top().first>=arr[i]) st.pop();
            if(st.empty()) next[i]=n-i;
            else next[i]=st.top().second-i;
            st.push({arr[i],i});
        }
        
        stack<pair<int,int>> st2;
        for(int i=0; i<n; i++){
            while(!st2.empty() and st2.top().first>arr[i]) st2.pop();
            if(st2.empty()) prev[i]=i+1;
            else prev[i]=i-st2.top().second;
            st2.push({arr[i],i});
        }
//         for(int i=0; i<n; i++) cout<<next[i]<<" ";
//         cout<<endl;

//         for(int i=0; i<n; i++) cout<<prev[i]<<" ";
//         cout<<endl;

        long long res=0;
        for(int i=0; i<n; i++){
            // cout<<arr[i]<<" "<<prev[i]<<" "<<next[i]<<endl;
            long long prod = prev[i]%MOD;
            prod=(prod*next[i])%MOD;
            prod=(prod*arr[i])%MOD;
            // res+=(arr[i]*(prev[i])*(next[i]));
            res=(res+prod)%MOD;
            // cout<<res<<endl;
        }
        return res;
    }
};