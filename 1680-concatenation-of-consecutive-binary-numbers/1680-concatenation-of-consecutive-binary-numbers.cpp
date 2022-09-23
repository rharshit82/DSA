class Solution {
public:
    int noOfBits(int n){
        return log2(n)+1;
    }
    int concatenatedBinary(int n) {
        long res = 0;
        int MOD = 1e9 + 7;
        for(int i=1; i<=n; i++){
            int len = noOfBits(i);
            res = ((res<<len)%MOD+i)%MOD;
        }
        return res;
    }
};