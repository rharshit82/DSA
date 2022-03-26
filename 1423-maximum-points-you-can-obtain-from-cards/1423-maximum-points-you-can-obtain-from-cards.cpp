class Solution {
public:
     int maxScore(vector<int>& cardPoints, int k) {
        int res=0, n=cardPoints.size();
        int sum=0;
        for(int i=n-k; i<n;i++) res+=cardPoints[i]; 
        sum=res;
        for(int i=0;i<k;i++) {
            sum-=cardPoints[n-k+i];
            sum+=cardPoints[i];
            res=max(res,sum);
        }
        return res;
    }
};