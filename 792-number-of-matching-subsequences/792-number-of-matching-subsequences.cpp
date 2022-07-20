class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int res=0;
        vector<vector<int>> alpha(26);
        for(int i=0; i<s.size(); i++){
            alpha[s[i]-'a'].push_back(i);
        }
        for(auto &word: words){
            bool found=true;
            int x = -1;
            for(auto ch: word){
                auto it = upper_bound(alpha[ch-'a'].begin(), alpha[ch-'a'].end(), x);
                if(it==alpha[ch-'a'].end()){
                    found=false;
                    break;
                }
                else x = *it;
            }
            if(found) res++;
        }
        return res;
    }
};