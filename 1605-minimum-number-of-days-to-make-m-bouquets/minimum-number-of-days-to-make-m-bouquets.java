class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        int mx = Arrays.stream(bloomDay).max().getAsInt();
        int low = 1, high = mx;
        while(low<=high){
            int mid = low + (high-low)/2;
            boolean canDo = check(mid, bloomDay, m, k);
            if(canDo){
                high = mid-1;
            } else low = mid+1;
        }
        return low == mx+1 ? -1 : low;
    }
    boolean check(int days, int[] bloomDay, int m, int k){
        int bouq = 0;
        int curr = 0;
        for(int i=0; i<bloomDay.length; i++){
            if(bloomDay[i] <=days){
                curr++;
            } else curr = 0;
            if(curr == k){
                bouq++;
                curr = 0;
            }
            
        }
        return bouq >= m;
    }
}