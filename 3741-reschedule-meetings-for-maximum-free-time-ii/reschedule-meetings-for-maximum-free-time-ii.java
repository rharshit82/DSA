class Solution {
    public int maxFreeTime(int eventTime, int[] startTime, int[] endTime) {
        int n = startTime.length;
        int[] gaps = new int[n+1];
        gaps[0] = startTime[0];

        for(int i=1; i<n; i++){
            gaps[i] = startTime[i] - endTime[i-1];
        }
        gaps[n] = eventTime - endTime[n-1];

        int[] pre = new int[n+1];
        int[] suf = new int[n+1];
        for(int i=1; i<=n; i++){
            pre[i] = Math.max(pre[i-1], i-2 >=0? gaps[i-2] : 0);
        }
        for(int i=n-1; i>=0; i--){
            suf[i] = Math.max(suf[i+1], gaps[i+1]);
        }

        int res = 0;

        for(int i=1; i<=n; i++){
            int duration = endTime[i-1] - startTime[i-1];
            if(suf[i] >= duration || pre[i] >= duration){
                res = Math.max(res, gaps[i-1] + gaps[i] + duration);
            }
            res = Math.max(res, gaps[i-1] + gaps[i]);
        }
        return res;
    }
}