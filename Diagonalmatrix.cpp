/*
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.
Example:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]
Explanation:

Note:
	1. The total number of elements of the given matrix will not exceed 10,000.

From <https://leetcode.com/explore/learn/card/array-and-string/202/introduction-to-2d-array/1167/>
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int rows = matrix.size();
        if(rows == 0) {
            return result;
        }
        int columns = matrix[0].size();
        // Map where key as sum of indices and values as the list which has same sum of indices.
        map<int,list<int>> myMap;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                list<int> temp = myMap[i+j];
                temp.push_back(matrix[i][j]);
                myMap[i+j] = temp;
            }
        }
        int direction = 0;

        //Add the values in the map to the result by altering the direction for every other key.
        for(auto i = myMap.begin(); i != myMap.end(); i++) {
            list<int> second = i->second;

            if(direction % 2 == 0) {
               second.reverse();
               for(auto k = second.begin(); k != second.end(); k++) {
                    result.push_back(*k);
                }
            }
            else
            for(auto k = second.begin(); k != second.end(); k++) {
                  result.push_back(*k); ;
            }
            direction++;
        }
        return result;
    }
};

