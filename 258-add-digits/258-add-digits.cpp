class Solution {
public:
    int addDigits(int num) {
        int temp=0;
        while(num){
            temp+=num%10;
            num/=10;
        }
        if(temp>=0 and temp<=9){
             return temp;
            
        }
        else{
           return addDigits(temp);
        }
    }
};