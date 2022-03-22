class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int res= INT_MIN;
        while(i<j){
            res=max(res,min(height[i],height[j])*(j-i));
            if(height[i]>height[j]){
                j--;
            } else i++;
        }
        return res;
    }
};