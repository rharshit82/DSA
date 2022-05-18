class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res="";
        while(columnNumber){
            columnNumber--;
            char ch = (columnNumber)%26 + 'A' ;
            res+=ch;
            columnNumber/=26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};