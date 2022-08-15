class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string normal = normalize(pattern);
        vector<string> res;
        for(auto word: words){
            if(normal == normalize(word)){
                res.push_back(word);
            }
        }
        return res;
    }
    string normalize(string word){
        unordered_map<char,char> mp;
        char init = 'a';
        for(auto ch: word){
            mp[ch] = init++;
        }
        for(auto &ch: word){
            ch = mp[ch];
        }
        return word;
    }
};