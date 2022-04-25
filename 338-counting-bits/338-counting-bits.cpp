class Solution {
public:
    int findOne(int n){
        int res=0;
        int mask =1;
        for(int j=0; j<31; j++){
            if((mask<<j)&n) res++;
        }
        return res;
    }
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0; i<=n; i++) res.push_back(findOne(i));
        return res;
    }
};