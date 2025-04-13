class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int low = Arrays.stream(weights).max().getAsInt();
        int high = Arrays.stream(weights).sum();

        while (low <= high) {
            int mid = low + (high - low) / 2;
            boolean canShip = findCanShip(weights, days, mid);
            if (canShip) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }

        }
        return low;

    }

    boolean findCanShip(int[] weights, int days, int mid) {
        int sum = 0;
        int currDays = 1;
        for (int i = 0; i < weights.length; i++) {
            if (sum + weights[i] > mid) {
                currDays++;
                sum = 0;
            }
            sum += weights[i];
        }
        return currDays <= days;
    }
}