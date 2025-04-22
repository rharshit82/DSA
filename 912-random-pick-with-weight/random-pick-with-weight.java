class Solution {
    Random r;
    int[] w;
    public Solution(int[] _w) {
        w = _w;
        r = new Random();
        for(int i=1; i<w.length; i++){
            w[i]+= w[i-1];
        }
    }
    
    public int pickIndex() {
        int random = r.nextInt(w[w.length-1]) + 1;
        int low = 0, high = w.length-1;
        while(low <=high){
            int mid = low + (high-low)/2;
            if(random <= w[mid]){
                high = mid - 1;
                
            } else if(random > mid){
                low = mid + 1;
            } 
        } 
        return low;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */