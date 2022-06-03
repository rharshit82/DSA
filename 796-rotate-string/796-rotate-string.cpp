class Solution {
public:
   bool rotateString(string s, string goal) {
        if(s==goal){
            return true;
        }
        for(int i=0;i<s.length()-1;i++){
            s.push_back(s[0]);
            s.erase(s.begin());
            if(s==goal){
                return true;
            }
        }
        return false;
    }
};