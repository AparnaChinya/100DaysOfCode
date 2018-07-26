/*
Spiral Matrix
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

From <https://leetcode.com/explore/interview/card/microsoft/30/array-and-strings/178/>

*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        if(matrix.size() == 0) {
            return vector<int>();
        }

        int direction = 0;
        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;


        while(left <= right && top <= bottom) {
            if(direction == 0) {
                for(int i = left; i <= right; i++) {
                    result.push_back(matrix[top][i]);
                }
                top++;
            }
            else if(direction == 1) {
                for(int i = top; i <= bottom; i++) {
                    result.push_back(matrix[i][right]);
                }
                right--;
            }
            else if(direction == 2) {
                for(int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            else if(direction == 3) {
                for(int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }

            direction = (direction + 1) % 4;
        }
        return result;
    }
};

