class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c=0;
        int a=1;
        for(int j=0; j<32; j++){
            c+= (((a<<j) & n)!=0);
        }
        return c;
    }
};