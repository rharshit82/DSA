class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int a1[256], a2[256];
        
        for(int i=0; i<256; i++){
            a1[i] = a2[i] = -1;
        }
        
        for(int i=0; i<s.size(); i++){
            if(a1[s[i]]!=a2[t[i]]) return false;
            a1[s[i]] = i;
            a2[t[i]] = i;
        }
        return true;
    }
};