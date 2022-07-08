class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int hare = 0;
        int tortoise = 0;
        int n=nums.size();
        do{
            hare = nums[nums[hare]];
            tortoise = nums[tortoise];
        }while(hare!=tortoise);
        
         tortoise=0;
        while(tortoise!=hare){
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        return tortoise;
    }
};