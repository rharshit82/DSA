class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        if(st.find(endWord)==st.end()) return 0;
        int depth = 0;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            int sz = q.size();
            depth++;
            for(int k=0; k<sz; k++){
                string curr = q.front(); q.pop();
                for(int i=0; i<curr.size(); i++){
                    string temp = curr;
                    for(char ch='a'; ch<='z'; ch++){
                        temp[i] = ch;
                        if(temp.compare(curr)==0) continue;
                        if(temp.compare(endWord)==0) return depth+1;
                        if(st.find(temp)!=st.end()){
                            st.erase(temp);
                            q.push(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};