class Solution {
public:
    int reverse(int x) {
        int res=0;
        while(x){
            if(res>INT_MAX/10) return 0; 
            if(res<INT_MIN/10) return 0; 
            res=res*10+x%10;
            x/=10;
        }
        if(res>INT_MAX) return 0;
        if(res<INT_MIN) return 0; 
        return res;
    }
};