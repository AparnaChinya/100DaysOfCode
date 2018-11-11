/*
672. Bulb Switcher II
There is a room with n lights which are turned on initially and 4 buttons on the wall. After performing exactly m unknown operations towards buttons, you need to return how many different kinds of status of the n lights could be.
Suppose n lights are labeled as number [1, 2, 3 ..., n], function of these 4 buttons are given below:
	1. Flip all the lights.
	2. Flip lights with even numbers.
	3. Flip lights with odd numbers.
	4. Flip lights with (3k + 1) numbers, k = 0, 1, 2, ...
Example 1:
Input: n = 1, m = 1.
Output: 2
Explanation: Status can be: [on], [off]
Example 2:
Input: n = 2, m = 1.
Output: 3
Explanation: Status can be: [on, off], [off, on], [off, off]
Example 3:
Input: n = 3, m = 1.
Output: 4
Explanation: Status can be: [off, on, off], [on, off, on], [off, off, off], [off, on, on].
Note: n and m both fit in range [0, 1000].

From <https://leetcode.com/problems/bulb-switcher-ii/description/>
*/

class Solution {
public:
    int flipLights(int n, int m) {
        n = min(n,3);
        if(m == 0) {
            return 1;
        }
        if(m == 1) {
            return n == 1? 2 : n == 2 ? 3 : 4;
        }
        if(m == 2) {
            return n == 1? 2 : n == 2 ? 4 : 7;
        }
        return n == 1 ? 2 : n == 2 ? 4 : 8;
    }
};

