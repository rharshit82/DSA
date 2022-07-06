class Solution {
public:
    int solve(int x, vector<int>&dp){
        if(x<=1) return 0;
        if(dp[x]!=-1) return dp[x];
        if(x%2==0){
            return dp[x]=1 + solve(x/2,dp);
        } else{
            return dp[x]=1+ solve(3*x+1,dp);
        }
        return 0;
    }
    static bool sortbysec(pair<int,int> a, pair<int,int> b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second<b.second;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> arr(hi-lo+1);
        vector<int> dp(1000000,-1);
        int var=0;
        for(int i=lo; i<=hi; i++){
            arr[var++] = {i,solve(i,dp)};
        }
        
        sort(arr.begin(),arr.end(),sortbysec);
       
        return arr[k-1].first;
    }
};