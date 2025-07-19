class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> {
            if(a[0] == b[0]) return a[1] - b[1];
            return a[0] - b[0];
        });
        int prevEnd = intervals[0][1];
        int res = 0;
        for(int i=1; i<intervals.length; i++){
            int curStart = intervals[i][0];
            int curEnd = intervals[i][1];
            if(prevEnd > curStart){
                res++;
                prevEnd = Math.min(prevEnd, curEnd);
            } else prevEnd = curEnd;
        }
        return res;

    }
}