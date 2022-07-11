class Solution {
public:
    bool isPalindrome(string s) {
        string t= "";
        for(int i=0; i<s.size(); i++){
            if(isalpha(s[i])){
                t+=tolower(s[i]);
            } else if(isdigit(s[i])){
                t+=s[i];
            }
        }
        int n=t.size();
        for(int i=0; i<n; i++){
            if(t[i]!=t[n-i-1]) return false;
        }
        return true;
    }
};