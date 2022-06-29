class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int low = 0, high=n-1;
        int res = 0;
        while(low<=high){
            res = max(res, min(height[high],height[low])*(high-low));
            if(height[low]>height[high]){
                high--;
            } else{
                low++;
            }
        }
        return res;
    }
};