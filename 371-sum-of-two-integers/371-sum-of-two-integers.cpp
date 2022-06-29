class Solution {
public:
    int getSum(int a, int b) {
        unsigned XOR = a^b;
        unsigned AND = a&b;
        AND = AND<<1;
        return XOR+AND;
    }
};