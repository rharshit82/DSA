class Solution {
public:
    int digSum(int dig){
        int sum=0;
        while(dig){
            int tmp= dig%10;
            sum+= tmp*tmp;
            dig/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do{
            slow=digSum(slow);
            fast=digSum(fast);
            fast=digSum(fast);
        } while(slow!=fast);
        return slow==1;
    }
};