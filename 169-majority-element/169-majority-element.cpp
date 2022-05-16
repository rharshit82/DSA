class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majele=nums[0];
        int count=1;
        int n=nums.size();
        for(int i=1; i<n; i++){
            if(nums[i]==majele) count++;
            else count--;
            if(count==0){
                majele=nums[i];
                count=1;
            }
        }
        return majele;
    }
};