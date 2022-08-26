class Solution {
public:
    bool reorderedPowerOf2(int n) {
        long long C = counter(n);
        for(int i=0; i<32; i++){
            if(counter(1<<i) == C) return true;
        }
        return false;
    }
    int counter(int n){
        int res = 0;
        while(n){
            res+= pow(10, n%10);
            n/=10;
        }
        return res;
    }
};