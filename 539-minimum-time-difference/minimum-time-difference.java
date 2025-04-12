class Solution {
    public int findMinDifference(List<String> timePoints) {
        List<Integer> timeInMinutePoints = new ArrayList<>();

        for(String time : timePoints){
            int timeInMinutes = convertTimeStringToMinutes(time);
            timeInMinutePoints.add(timeInMinutes);
        }

        Collections.sort(timeInMinutePoints, (a, b) -> Integer.compare(a, b));
        int minDiff = findMinDiff(timeInMinutePoints.get(0), timeInMinutePoints.get(timeInMinutePoints.size() - 1));
        for(int i=1; i<timeInMinutePoints.size(); i++){
            minDiff = Math.min(minDiff, findMinDiff(timeInMinutePoints.get(i), timeInMinutePoints.get(i-1)));
        }
        return minDiff;
    }

    int findMinDiff(int time1, int time2){
        return Math.min(Math.abs(time1-time2), 24 * 60 - (time2 - time1));
    }
    int convertTimeStringToMinutes(String time){
        String[] timeParts = time.split(":");
        int hours = Integer.parseInt(timeParts[0]);
        int minutes = Integer.parseInt(timeParts[1]);
        return hours*60 + minutes;
    }
}