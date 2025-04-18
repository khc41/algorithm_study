class Solution {
    public boolean canJump(int[] nums) {
        int maxMove = nums[0];
        if(nums.length == 1){
            return true;
        }
        for(int i = 0 ; i < nums.length; i++){
            if(i == nums.length - 1){
                return true;
            }
            maxMove = Math.max(maxMove, i + nums[i]);
            if(maxMove == i){
                return false;
            }
        }
        return false;
    }
}