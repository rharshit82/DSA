class Solution {
    public int maxTaskAssign(int[] tasks, int[] workers, int pills, int strength) {
        int res = 0;
        int n = tasks.length;
        int m = workers.length;
        Arrays.sort(tasks);
        Arrays.sort(workers);
        int low = 0, high = Math.min(m, n);
        while(low <= high){
            int mid = low + (high-low)/2;
            if(canAssign(mid, tasks, workers, pills, strength)){
                low = mid + 1;
            } else high = mid-1;
        }
        return high;
    }

    public boolean canAssign(int k, int[] tasks, int[] workers, int pills, int strength){
        TreeMap<Integer, Integer> avail = new TreeMap<>();

        for (int i = workers.length - k; i < workers.length; i++){
            avail.put(workers[i], avail.getOrDefault(workers[i], 0) + 1);
        }
        int usedPills = 0;

        for (int i = k - 1; i >= 0; i--) {
            int task = tasks[i];
            if(task <= avail.lastKey()){
                decrement(avail, avail.lastKey());
            } else{
                Integer ky = avail.ceilingKey(task - strength);
                if(ky == null || ++usedPills > pills){
                    return false;
                }
                decrement(avail, ky);
            }
        }
        return true;
    }
    void decrement(TreeMap<Integer, Integer> avail, int key){
        int cnt = avail.get(key);
        if(cnt == 1) avail.remove(key);
        else avail.put(key, cnt-1);
    }
}