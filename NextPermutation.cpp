/*
31. Next Permutation
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place and use only constant extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

From <https://leetcode.com/problems/next-permutation/description/>

*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int last = nums.size()-2;

        while(last >= 0 && nums[last+1] <= nums[last]) {
            last--;
        }
        if(last >= 0) {
            int j = nums.size()-1;
            while(j >= 0 && nums[j] <= nums[last]) {
                j--;
            }
            swap(nums[last],nums[j]);
        }

        reverse(nums.begin()+last+1,nums.end());
    }
};

