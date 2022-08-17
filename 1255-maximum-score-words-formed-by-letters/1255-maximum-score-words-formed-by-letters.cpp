class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int res = 0;
        vector<int> farr(26, 0);
        for(int i=0; i<letters.size(); i++){
            farr[letters[i] - 'a']++;
        }
        return findMax(0, words, farr, score);
    }
    int findMax(int i, vector<string>& words, vector<int>& farr, vector<int>&score){
        if(i== words.size()) return 0;
        int notTake = findMax(i+1, words, farr, score);
        bool f=false;
        int currscore = 0;
        for(int j=0; j<words[i].size(); j++){
            char ch = words[i][j];
            if(farr[ch-'a']<=0){
                f=true;
            }
            currscore+=score[ch-'a'];
            farr[ch-'a']--;
        }
        int take = 0;
        if(!f){
            take = currscore + findMax(i+1, words, farr, score);
        }
        for(int j=0; j<words[i].size(); j++){
            char ch = words[i][j];
            farr[ch-'a']++;
        }
        return max(take, notTake);
    }
};