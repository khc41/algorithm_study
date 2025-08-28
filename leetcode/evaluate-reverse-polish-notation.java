class Solution {
    public int evalRPN(String[] tokens) {
        Deque<Integer> nums = new ArrayDeque<>();
        for (String token : tokens) {
            if ("+".equals(token) || "-".equals(token) || "*".equals(token) || "/".equals(token)) {
                int right = nums.pop();
                int left = nums.pop();

                switch (token) {
                    case "+":
                        nums.push(left + right);
                        break;
                    case "-":
                        nums.push(left - right);
                        break;
                    case "*":
                        nums.push(left * right);
                        break;
                    case "/":
                        nums.push(left / right);
                        break;
                }
            } else {
                nums.push(Integer.valueOf(token));
            }
        }
        return nums.pop();
    }
}