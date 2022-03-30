class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return 0;
        int ladder=nums[0];
        int stairs=nums[0];
        int jumps=1;
        for(int i=1; i<n; i++){
            if(i==n-1) return jumps;
            stairs--;
            ladder=max(ladder, i+ nums[i]);
            if(stairs==0){
                stairs=ladder-i;
                jumps++;
            }
        }
        return jumps;
    }
};