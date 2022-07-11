class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n=arr.size();
        int sum=0;
        
        for(int i=0; i<k; i++){
            sum+=arr[i];
        }
        
        int res = sum;
        
        for(int i=n-1, j=k-1; i>=n-k; i--, j--){
            sum-=arr[j];  
            sum+=arr[i];
            res = max(res, sum);
        }
        return res;
    }
};