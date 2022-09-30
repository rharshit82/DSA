class Solution {
public:
    int minSwaps(string s) {
        int balance = 0;
        int n = s.size();
        int j = n-1;
        int res = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '[') balance++;
            else balance--;
            if(balance==-1){
                while(j>i and s[j]!='[') j--;
                swap(s[i], s[j]);
                j--;
                res++;
                balance = 1;
            }
        }
        return res;
    }
};