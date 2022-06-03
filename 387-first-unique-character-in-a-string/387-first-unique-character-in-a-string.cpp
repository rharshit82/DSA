class Solution {
public:
    int firstUniqChar(string s) {
        map<char,vector<int>> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]].push_back(i);
        }
        int mn=INT_MAX;
        for(auto k: mp){
            if(k.second.size()==1){
                mn = min (mn, k.second[0]);
            }
        }
        return (mn==INT_MAX? -1: mn);
    }
};