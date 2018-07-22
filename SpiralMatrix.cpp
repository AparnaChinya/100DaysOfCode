/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
Example 1:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:
Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

From <https://leetcode.com/explore/learn/card/array-and-string/202/introduction-to-2d-array/1168/>

 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result(0);
        int top = 0;
        int bottom = matrix.size() - 1;
        if(matrix.size() == 0) return result;

        int right = matrix[0].size() - 1;
        int left = 0;
        int direction = 0;


        while (left <= right && top <= bottom) {
            // cout << left << right << top << bottom << endl;
            if (direction == 0) { //Right
                for(int i = left; i <= right; i++) {
                   result.push_back(matrix[top][i]);
                }

                top++;
            }
            else if (direction == 1) { //Down
                for(int i = top; i <= bottom; i++) {
                   result.push_back(matrix[i][right]);
                }
                right--;
            }
            else if (direction == 2) { // left
                for(int i = right; i >= left; i--) {
                   result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            else if (direction == 3) { //Up
                for( int i = bottom; i >= top; i--) {
                      cout<<matrix[i][left]<< " ";
                   }
                left++;
            }
            direction = (direction + 1) % 4;
        }

        return result;
    }
};
