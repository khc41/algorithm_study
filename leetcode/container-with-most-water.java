class Solution {
    public int maxArea(int[] height) {
        int result = 0;
        int min = 0;
        int max = height.length - 1;
        while (max > min) {
            result = Math.max(result, (max - min) * Math.min(height[min], height[max]));
            if (height[min] > height[max]) {
                max--;
            } else {
                min++;
            }
        }
        return result;
    }
}