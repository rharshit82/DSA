class Solution {
public:
    // 1 -> 0
    // 2 -> CP
    // 3 -> CPP
    // 4 -> CPPP/ CPCP
    // 5 -> CPPPP
    // 6 -> CPCPP/ CPPCP
    // 7 -> CPPPPPP
    // 8 -> CPCPCP/ CPCPPP/ CPPPCP
    // 9 -> CPPCPP
    // 19 -> 2*3*3: CP=2, CPCPP = 2*3 CPCPPCPP = 2*3*3
    int minSteps(int n) {
        int ans=0;
        for(int i=2; i*i <=n;){
            if(n%i==0){
                ans+=i;
                n/=i;
            }
            else i++;
        }
        if(n!=1){
            ans+=n;
        }
        return ans;
    }
};