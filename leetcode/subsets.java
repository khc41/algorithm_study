class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        getSubset(0, new ArrayList<>(), result, nums);
        return result;
    }

    public void getSubset(int index, List<Integer> array, List<List<Integer>> result, int[] nums) {
        if (index >= nums.length) {
            result.add(array);
            return;
        }
        getSubset(index + 1, array, result, nums);
        List<Integer> newArray = new ArrayList<>(array);
        newArray.add(nums[index]);
        getSubset(index + 1, newArray, result, nums);
    }
}