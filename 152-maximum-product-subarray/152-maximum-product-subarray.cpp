class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int prod=1;
        int res=INT_MIN;
        for(int i=0; i<n; i++){
            prod = prod * nums[i];
           
            res=max(prod,res);
            
            if(prod==0){
                prod=1;
            }
        }
        prod=1;
        for(int i=n-1; i>=0; i--){
            prod = prod * nums[i];
            
            res=max(prod,res);
            
            if(prod==0){
                prod=1;
            }
        }
        return res;
    }
};