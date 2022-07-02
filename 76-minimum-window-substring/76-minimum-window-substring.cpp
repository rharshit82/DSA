class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int k=t.size();
        map<int,int> mps,mpt;
        for(int i=0; i<k; i++){
            mpt[t[i]]++;
        }
        int have=0;
        int need=mpt.size();
        int resSize=INT_MAX;
        string res="";
        int i=0;
        for(int j=0; j<n; j++){
            char ch= s[j];
            mps[ch]++;
            if(mpt.find(ch)!=mpt.end() and mps[ch]==mpt[ch]){
                have++;
            }
            if(have==need){
                
                while(have==need and i<n){
                    if((j-i+1)<resSize){
                    resSize=j-i+1;
                    res=s.substr(i,j-i+1);
                    }
                    mps[s[i]]--;
                    if(mpt.find(s[i])!=mpt.end() and mps[s[i]]<mpt[s[i]]){
                        have--;
                    }
                    i++;
                }
            }
        }
        return res;
    }
};