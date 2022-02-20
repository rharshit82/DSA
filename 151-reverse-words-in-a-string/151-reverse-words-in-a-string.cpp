class Solution {
public:
    string reverseWords(string s) {
        string res="";
        string sn="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' ' and sn.size()==0)  continue;
            if(s[i]==' '){
                res=sn+' '+res;
                sn="";
            }else{
                sn+=s[i];
            }
        }
        if(sn.size()>0){
             res=sn+" "+res;
        }
        res.pop_back();
        return res;
    }
};