class Solution {

    public double separateSquares(int[][] squares) {
        double totalArea = 0;
        int maxY = 0;
        for (int[] sq : squares) {
            totalArea += (double) sq[2] * sq[2];
            maxY = Math.max(maxY, sq[1] + sq[2]);
        }

        double low = 0, high = maxY, ans = 0, epsilon = 1e-6;

        while (high - low > epsilon) {
            double mid = (low + high) / 2.0;
            double below = getAreaBelow(mid, squares);

            if (below >= totalArea / 2.0) {
                ans = mid;
                high = mid;
            } else {
                low = mid;
            }
        }

        return ans;
    }

    double getAreaBelow(double cutY, int[][] squares) {
        double below = 0;
        for (int[] square : squares) {
            double y = square[1];
            double sz = square[2];
            double y2 = y + sz;

            if (y2 <= cutY) {
                // Fully below
                below += sz * sz;
            } else if (y < cutY) {
                // Partially below
                below += (cutY - y) * sz;
            }
            // else: fully above → contributes nothing
        }
        return below;
    }
}
