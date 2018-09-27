/*
279. Perfect Squares
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
Example 1:
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

From <https://leetcode.com/problems/perfect-squares/description/>
*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> DP{0};
        //Add to the vector until the size becomes n
        while(DP.size() <= n) {
            int m = DP.size();
            int squares = INT_MAX;
            //For numbers from 1 to sqrt of size of the vector, check the min of squares
            for(int i = 1; i <= sqrt(m); i++) {
                squares = min(squares, DP[m - i*i] + 1);
            }
            DP.push_back(squares);
        }


        return DP[n];
    }
};
