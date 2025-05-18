class DetectSquares {
    Map<Integer, Map<Integer, Integer>> pointCount;
    public DetectSquares() {
        pointCount = new HashMap<>();
    }
    
    public void add(int[] point) {
        int x = point[0];
        int y = point[1];

        pointCount.putIfAbsent(x, new HashMap<>());
        Map<Integer, Integer> yMap = pointCount.get(x);
        yMap.put(y, yMap.getOrDefault(y, 0) + 1);
        pointCount.put(x, yMap);
    }
    
   
    public int count(int[] point) {
        int x = point[0];
        int y = point[1];
        int res = 0;
        if(!pointCount.containsKey(x)) return res;
        for(int yy : pointCount.get(x).keySet()){
            if(yy == y) continue;
            int dis = Math.abs(yy - y);
            for(int d : new int[]{+dis, -dis}){
                int xx = x + d;

                if(pointCount.containsKey(xx)){
                    int c1 = pointCount.get(xx).getOrDefault(y, 0);
                    int c2 = pointCount.get(x).getOrDefault(yy, 0);
                    int c3 = pointCount.get(xx).getOrDefault(yy, 0);
                    res+= c1 * c2 * c3;
                }

            }
        }
        return res;
        
    }
}

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares obj = new DetectSquares();
 * obj.add(point);
 * int param_2 = obj.count(point);
 */