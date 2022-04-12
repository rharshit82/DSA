class Solution {
public:
    int ind(vector<int>&arr){
        int n = arr.size();
        int low = 0, high=n-1;
        while(high>=low){
            int mid = low + (high-low)/2;
            if(arr[mid]>=0) low=mid+1;
            else high=mid-1;
        }
        return n-high-1;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0; i<grid.size(); i++){
            res+=ind(grid[i]);
        }
        return res;
    }
};