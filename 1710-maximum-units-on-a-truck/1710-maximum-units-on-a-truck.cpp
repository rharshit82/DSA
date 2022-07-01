class Solution {
public:
   
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();
        vector<int> bucket(1001, -1);
        for(int i=0; i<n; i++){
            int boxes = boxTypes[i][0];
            int units = boxTypes[i][1];
            
            if(bucket[units]==-1){
                bucket[units] = boxes;
            } else{
                bucket[units] += boxes;
            }
        }
        int res=0;
        for(int i=1000; i>=0 and truckSize>0; i--){
            if(bucket[i]==-1) continue;
            if(bucket[i]<=truckSize){
                res+=bucket[i]*i;
                truckSize-=bucket[i];
            } else{
                res+=truckSize*i;
                break;
            }
        }
        return res;
    }
};