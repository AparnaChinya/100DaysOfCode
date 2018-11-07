/*'
311. Sparse Matrix Multiplication
Given two sparse matrices A and B, return the result of AB.
You may assume that A's column number is equal to B's row number.
Example:
Input:
A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]
B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]
Output:
|  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |

From <https://leetcode.com/problems/sparse-matrix-multiplication/description/>
*/

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> result(A.size(),vector<int>(B[0].size(),0));
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < A[0].size(); j++) {
                if(A[i][j] != 0) {
                    for(int k = 0; k < B[0].size(); k++) {
                        if(B[j][k] != 0)
                            result[i][k] += (A[i][j] * B[j][k]);
                    }
                }
            }
        }
        return result;
    }
};
