class Solution {
public:
    bool solve(int i, vector<int>& matchsticks, vector<int>& arr, int &target){
        if(i==matchsticks.size()){
            for(int i=0; i<3; i++){
                if(arr[i]!=arr[i+1]) return false;
            }
            return true;
        }
        for(int j=0; j<4; j++){
            
            if(arr[j]<target){
                int k;
                for( k=0; k<j; k++){
                    if(arr[k]==arr[j])
                        break;
                }
                if(k!=j) continue;
                arr[j]+=matchsticks[i];
                if(solve(i+1, matchsticks, arr, target)) return true;
                arr[j]-=matchsticks[i];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        for(int i=0; i<matchsticks.size(); i++){
            sum+=matchsticks[i];
        }
        if(sum%4!=0) return false;
        vector<int> arr(4,0);
        int target= sum/4;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return solve(0,matchsticks,arr,target);
    }
};