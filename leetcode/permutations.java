class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        boolean[] visited = new boolean[nums.length];
        permutation(new ArrayList<>(), visited, nums, result);
        return result;
    }

    public void permutation(List<Integer> cur, boolean[] visited, int[] nums, List<List<Integer>> result) {
        if (cur.size() >= nums.length) {
            List<Integer> newArray = new ArrayList<>(cur);
            result.add(newArray);
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (visited[i] == false) {
                visited[i] = true;
                cur.add(nums[i]);
                permutation(cur, visited, nums, result);
                cur.removeLast();
                visited[i] = false;
            }
        }
    }
}