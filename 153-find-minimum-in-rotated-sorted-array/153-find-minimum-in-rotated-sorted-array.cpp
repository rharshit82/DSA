class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        int low = 0, high=n-1;
        int res = INT_MAX;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid]<=arr[high]){
                res=min(arr[mid],res);
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return res;
    }
};