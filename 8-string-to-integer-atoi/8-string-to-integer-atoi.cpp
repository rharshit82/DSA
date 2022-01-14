class Solution {
public:
    int myAtoi(string s) {
            int ans = 0;
    int sign = 1;
    int i=0;
    while(s[i] == ' ') i++;
    if(s[i] == '-' || s[i] == '+'){
        if(s[i] == '-')sign = -1;
        i++;
    }
    while(s[i]>='0' && s[i]<='9'){
        if(ans> INT_MAX/10 || (ans == INT_MAX / 10 && s[i] - '0' > 7)){
            if(sign == 1) return INT_MAX;
            else return INT_MIN;
        }
        ans=10*ans+(s[i]-'0');
        i++;
    }
    
    return sign*ans;
    }
};