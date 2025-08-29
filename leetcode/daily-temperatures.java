class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        Stack<Integer> stack = new Stack<>();
        int[] result = new int[temperatures.length];
        stack.add(0);
        int prev = temperatures[0];
        for (int i = 1; i < temperatures.length; i++) {
            if (prev > temperatures[i]) {
                stack.add(i);
                prev = temperatures[i];
                continue;
            }
            while (!stack.isEmpty()) {
                int index = stack.pop();
                if (temperatures[index] < temperatures[i]) {
                    result[index] = i - index;
                } else {
                    stack.add(index);
                    break;
                }
            }
            stack.add(i);
            prev = temperatures[i];
        }
        return result;
    }
}