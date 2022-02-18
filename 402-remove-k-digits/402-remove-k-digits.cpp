class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.length() == k) return "0";
        vector<char> s;
        for(int i=0;i<num.size();i++){
            while(k > 0 && !s.empty() && s.back() > num[i]){
                s.pop_back();
                k--;
            }
            s.push_back(num[i]);
        }
        while(k--) s.pop_back();
        string res="";
        for(auto i: s){
            if(i=='0' and res.empty()) continue;
            res+=i;
        }
        return res.empty()?"0": res;
        
    }
};