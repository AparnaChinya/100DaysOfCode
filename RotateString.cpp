/*
796. Rotate String
We are given two strings, A and B.
A shift on A consists of taking string A and moving the leftmost character to the rightmost position. For example, if A = 'abcde', then it will be 'bcdea' after one shift on A. Return True if and only if A can become B after some number of shifts on A.
Example 1:
Input: A = 'abcde', B = 'cdeab'
Output: true
Example 2:
Input: A = 'abcde', B = 'abced'
Output: false
Note:
	• A and B will have length at most 100.

From <https://leetcode.com/problems/rotate-string/description/>

*/

class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size() != B.size()) {
            return false;
        }
        if(A == B) {
            return true;
        }
        for(int i = 0; i < A.size(); i++) {
            rotate(A.begin(),A.begin()+1,A.end());
            if(A==B) {
                return true;
            }
        }
        return false;
    }
};

