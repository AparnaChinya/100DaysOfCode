/* Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
Note that the row index starts from 0.

In Pascal's triangle, each number is the sum of the two numbers directly above it.
Example:
Input: 3
Output: [1,3,3,1]

From <https://leetcode.com/explore/learn/card/array-and-string/204/conclusion/1171/>
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
       vector<int> result;
       long C = 1;
        // Binomial Coefficient with O(K) space
        for(int j = 1; j <= rowIndex+1; j++) {
             result.push_back(C);
             C = C * (rowIndex+1-j)/j;
        }

        return result;
    }
};

