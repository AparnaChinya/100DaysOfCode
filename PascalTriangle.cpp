/* Pascal's Triangle

Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

From <https://leetcode.com/explore/learn/card/array-and-string/202/introduction-to-2d-array/1170/>  */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        // Using Binomial Coefficient
        for(int line = 1; line <= numRows; line++) {
          int C = 1;
          vector<int> temp;
          for(int j = 1; j <= line; j++) {
              temp.push_back(C);
              C = C*(line-j)/j;
          }
          result.push_back(temp);
        }
        return result;
    }
};

