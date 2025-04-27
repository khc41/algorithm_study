class Solution {
    public int search(int[] nums, int target) {
        return binarySearch(nums, target, 0, nums.length - 1);
    }

    public int binarySearch(int[] nums, int value, int low, int high){
        if(high < low){
            return -1;
        }
        int mid = (high + low) / 2;
        if(nums[mid] == value){
            return mid;
        }
        if(nums[low] <= nums[mid]){
            if(nums[low] <= value && value < nums[mid]){
                return binarySearch(nums, value, low, mid - 1);
            } else{
                return binarySearch(nums, value, mid + 1, high);
            }
        } else {
            if(nums[mid] < value && value <= nums[high]){
                return binarySearch(nums, value, mid + 1, high);
            } else{
                return binarySearch(nums, value, low, mid - 1);
            }
        }
    }
}