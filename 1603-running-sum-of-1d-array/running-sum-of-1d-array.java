class Solution {
    public int[] runningSum(int[] nums) {
        List<Integer> arr=new ArrayList<>();
        arr.add(nums[0]);
        for(int i=1;i<nums.length;i++){
            arr.add(nums[i]+ arr.get(i-1));
        }
        for(int i=0;i<nums.length;i++){
            nums[i]=arr.get(i);
        }
        return nums;
    }
}