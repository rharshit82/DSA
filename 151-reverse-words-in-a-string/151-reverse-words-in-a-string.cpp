class Solution {
public:
    string reverseWords(string s) {
        string res="";
        int n=s.size();
        int i=0;
        while(i<n){
            if(s[i]==' '){
                i++;
            }
            else {
                string temp="";
                while(s[i]!=' ' and i<n){
                    temp+=s[i];
                    i++;
                }
                res=temp+' '+res;
            }
        }
        res.pop_back();
        return res;
    }
};