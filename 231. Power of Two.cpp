/*
Given an integer, write a function to determine if it is a power of two. 

From <https://leetcode.com/problems/power-of-two/> 

*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0&&!(n&(n-1));
    }
};

