class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int low = 0;
        int high=n-1;
        while(high>=low){
            int mid = low + (high-low)/2;
            if(arr[mid]<arr[mid+1]) low = mid+1;
            else high=mid-1;
        }
        return low;
    }
};