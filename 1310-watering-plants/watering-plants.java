class Solution {
    public int wateringPlants(int[] plants, int capacity) {
        int n = plants.length;
        int res = 0;
        int curr = 0;
        for(int i=0; i<n; i++){
            if(curr < plants[i]){
                res+= 2*i;
                curr = capacity;
            } 
            curr-=plants[i];
            res++;
        }
        return res;
    }
}