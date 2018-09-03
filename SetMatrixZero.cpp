/*
 Set Matrix Zeroes
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
Example 1:
Input:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:
Input:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:
	• A straight forward solution using O(mn) space is probably a bad idea.
	• A simple improvement uses O(m + n) space, but still not the best solution.
	• Could you devise a constant space solution?

From <https://leetcode.com/explore/interview/card/microsoft/30/array-and-strings/203/>

*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row = false;
        bool column = false;
        //Check if the first row has any zeros
        for(int i = 0; i < matrix.size(); i++) {
            if(matrix[i][0] == 0) {
                row = true;
                break;
            }
        }
        //Check if the first column has any zeros
        for(int i = 0; i < matrix[0].size(); i++) {
            if(matrix[0][i] == 0) {
                column = true;
                break;
            }
        }
        //Set the first row's and first column's element as 0 if any element in that row or column is 0
        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 1; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 1; j < matrix[0].size(); j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        //Set the first row and column to zero if it had any zeros
        if(row) {
            for(int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
        if(column) {
            for(int i = 0; i < matrix[0].size(); i++) {
                matrix[0][i] = 0;
            }
        }

    }
};

