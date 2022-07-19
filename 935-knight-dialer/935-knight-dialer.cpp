class Solution {
public:
    int knightDialer(int n) {
        if (n == 1) {
            return 10;
        }

        long num1 = 1; // 0
        long num2 = 4; // 1/3/7/9
        long num3 = 2; // 4/6
        long num4 = 2; // 2/8
        
        for (int i = 2; i <= n; i++) {
            long oldNum1 = num1;
            long oldNum2 = num2;
            long oldNum3 = num3;
            long oldNum4 = num4;
            
            num1 = num3;
            num4 = num2;
            num2 = (oldNum3 * 2 % 1000000007 + oldNum4 * 2 % 1000000007) % 1000000007;
            num3 = (oldNum1 * 2 % 1000000007 + oldNum2) % 1000000007;
        }
        
        return (int)((num1 + num2 + num3 + num4) % 1000000007);
    }
};

