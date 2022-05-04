class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto num: nums) mp[num]++;
        int res=0;
        for(auto it: mp){
            cout<<it.first<<" "<<it.second<<endl;
            if(k%2==0 and it.first==k/2){
                
                res+=it.second/2;
            }
            else{
                res+=min(it.second,mp[k-it.first]);
                mp[k-it.first]=0;
            }
        }
        return res;
    }
};