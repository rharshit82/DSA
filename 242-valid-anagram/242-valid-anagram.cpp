class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<char> sv(26);
        for(int i=0;i<s.size();i++){
            sv[s[i]-'a']++;
            sv[t[i]-'a']--;
        }
        bool res=true;
        for(int i=0;i<26;i++){
            if(sv[i]!=0) res=false;
        }
        return res;
        
    }
};