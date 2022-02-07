class Solution {
public:
    char findTheDifference(string s, string t) {
        char res=0;
        for(auto i: s){
           res=i^res;
        }
         for(auto i: t){
            res=i^res;
        }
        return res;
    }
};