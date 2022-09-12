class Solution {
public:
    int bagOfTokensScore(vector<int>& arr, int power) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int curr = 0;
        int low = 0, high = n-1;
        int res = 0;
        while(low<=high){
            if(arr[low]<=power){
                power-=arr[low];
                curr++;
                low++;
            } else if(curr>=1){
                power+=arr[high];
                curr--;
                high--;
            } else break;
            res = max(res, curr);
        }
        return res;
    }
};