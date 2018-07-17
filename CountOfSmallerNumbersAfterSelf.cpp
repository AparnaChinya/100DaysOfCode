/*
315. Count of Smaller Numbers After Self
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
Example:
Input: [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

From <https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/>

*/

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        //Can use self balancing binary tree OR use the STL.
        vector<int> mySet;
        vector<int> result(nums.size());

        //Keep on adding to the vector at the position of it
        for(int i = nums.size()-1; i >= 0; i--) {
            auto it = std::lower_bound(mySet.begin(),mySet.end(),nums[i]);
            result[i] = distance(mySet.begin(),it);
            mySet.insert(it,nums[i]);
        }
        return result;
    }
};

