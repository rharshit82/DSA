class Solution {
public:
    bool isPalindrome(string &s, int start, int end){
        while(start<=end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void func(int i, string &s, vector<string>&path, vector<vector<string>>&res){
        if(i==s.size()){
            res.push_back(path);
            return;
        }
        for(int j=i; j<s.size(); j++){
            if(isPalindrome(s,i,j)){
                path.push_back(s.substr(i, j-i+1));
                func(j+1,s,path,res);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        func(0,s,path,res);
        return res;
    }
};