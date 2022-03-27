class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            pq.push(nums[i]);
        }
        int res=0;
        double k=sum;
        while(pq.size()>0&& k>sum/2){
            double temp = pq.top(); pq.pop();
            double updatedTemp = temp/2;
            pq.push(updatedTemp);
            k-=updatedTemp;
            res++;
        }
        return res;
        
    }
};