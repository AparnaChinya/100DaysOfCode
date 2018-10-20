/*
74. Search a 2D Matrix
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
	• Integers in each row are sorted from left to right.
	• The first integer of each row is greater than the last integer of the previous row.
Example 1:
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false

From <https://leetcode.com/problems/search-a-2d-matrix/description/>
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size()-1;
        if(row == -1) {
            return false;
        }
        if(matrix[0].size() == 0) {
            return false;
        }
        int col = 0;

        while(row >= 0 && col < matrix[0].size()) {
            cout << matrix[row][col] << endl;
            if(matrix[row][col] > target) {
                row--;
            } else if(matrix[row][col] < target) {
                col++;
            } else if(matrix[row][col] == target){
                return true;
            }
        }
        return false;
    }
};
