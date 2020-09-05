/*

Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    int accumulation = 0; 
    int result = 0;
    
    map<int,int> seen;
    seen[0] = 1;
    
    for(int i = 0; i < nums.size(); i++){
        
        // we need to accumulate the total sum 
        accumulation += nums[i];
        
        // if ( accumulation- k = a number we've seen before) then that means 
        // accumulation- number = k
        // which means that set of numbers = k (since we are accumulating the sum)
        
        int complement = accumulation-k;
        
        // if we have seen the complement before
        if(seen.count(complement)){
            result += seen[complement]; 
        }
        if(seen.count(accumulation) == 0){
            seen[accumulation] = 1;
        }
        else{
            seen[accumulation] = seen[accumulation] + 1;
        }

    }
    return result;
}
};
