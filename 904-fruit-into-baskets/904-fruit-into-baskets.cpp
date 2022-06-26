class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n=arr.size();
        map<int,int> mp;
        int i=0;
        int res=0;
        for(int j=0; j<n; j++){
            mp[arr[j]]++;
            if(mp.size()>2){
                while(mp.size()>2){
                    if(mp[arr[i]]==1){
                        mp.erase(arr[i]);
                    } else{
                        mp[arr[i]]--;
                    }
                    i++;
                }
            }
            res = max(res, j-i+1);
        }
        return res;
    }
};