class Solution {
public:
    bool validPalindrome(string s) {
        int count=0;
        int n=s.size();
        // int j=s.size();
        // int i=0;
        for(int i=0; i<s.size()/2; i++){
            if(s[i]!=s[n-i-1]) return isPalindrome(s,i+1,n-i-1) or isPalindrome(s,i,n-i-2);
        }
        return true;
    }
    bool isPalindrome(string s, int i, int j){
        cout<<s[i]<<" "<<s[j]<<endl;
        while(j>i){
            if(s[i]!=s[j]) return false;
            j--;
            i++;
        }
        return true;
    }
};