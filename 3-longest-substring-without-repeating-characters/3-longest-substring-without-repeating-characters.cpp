class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int res = 0;
        for(int i=0; i<n; i++){
            set<int> mp;
            for(int j=i; j<n; j++){
                if(mp.find(s[j])!=mp.end()) break;
                else mp.insert(s[j]);
                res=max(res,j-i+1);
            }
        }
        return res;
    }
};