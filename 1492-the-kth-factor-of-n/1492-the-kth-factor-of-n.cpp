class Solution {
public:
    int kthFactor(int n, int k) {
        int p=1;
        int res=1;
        if(k==1) return 1;
        for(int i=2; i<=n; i++){
            if(n%i==0){
                res=i;
                p++;
            }
            if(p==k) break;
        }
        if(p!=k) return -1;
        return res;
    }
};