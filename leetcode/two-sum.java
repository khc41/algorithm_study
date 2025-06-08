class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < nums.length; i++){
            Integer cur = map.get(target-nums[i]);
            if(cur != null){
                return new int[] {cur, i};
            }
            map.put(nums[i], i);
        }
        return new int[] {0, 0};
    }
}