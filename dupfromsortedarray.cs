public class Solution {
    public int RemoveDuplicates(int[] nums) {
        if (nums.Length != 0){
            int count = 1;
            int new_index = 0;
            int number_on = nums[0];
            foreach (int x in nums){
                if (number_on != x){
                    nums[count++] = x;
                    number_on = x;
                }
            }
            return count;
        }
        else{
            return 0;
        }
    }
}
