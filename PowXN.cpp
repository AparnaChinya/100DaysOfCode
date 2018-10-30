/*
50. Pow(x, n)
Implement pow(x, n), which calculates x raised to the power n (xn).
Example 1:
Input: 2.00000, 10
Output: 1024.00000
Example 2:
Input: 2.10000, 3
Output: 9.26100
Example 3:
Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:
	• -100.0 < x < 100.0
	• n is a 32-bit signed integer, within the range [−231, 231 − 1]

From <https://leetcode.com/problems/powx-n/description/>


*/
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        double answer = 1;
        if(N < 0) {
            N = -N;
            x = 1/x;
        }
        double CP = x;

        for(long long i = N; i ; i = i/2) {
            if(i % 2 == 1) {
                answer = answer * CP;
            }
            CP = CP * CP;
        }
        return answer;
    }
};

