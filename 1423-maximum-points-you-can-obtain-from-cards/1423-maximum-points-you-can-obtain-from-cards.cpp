class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum=0;
        for(int i=n-1; i>=n-k; i--){
            sum+=cardPoints[i];
        }
        int res=INT_MIN;
        for(int i=0, j=n-k; j<=n-1; i++, j++){
            res=max(sum,res);
            sum-=cardPoints[j];
            sum+=cardPoints[i];
        }
         res=max(sum,res);
        return res;
    }
};