/*

120. Triangle

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

From <https://leetcode.com/problems/triangle/description/>


*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int result = INT_MAX;
        int ROW = triangle.size();
        if(ROW == 0) {
            return 0;
        }
        vector<vector<int>> myVector(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),0));
        myVector[0][0] = triangle[0][0];
        //JUST DOWN AND RIGHT
        for(int i = 1; i < triangle.size(); i++) {
            for(int j = 0; j < triangle[i].size(); j++) {

                int index1 = INT_MAX; int index2 = INT_MAX; int index3 = INT_MAX;

                if(i-1 >= 0 && j <= triangle[i-1].size()-1) {
                    index1 = myVector[i-1][j] + triangle[i][j];
                }
                if(i-1 >= 0 && j-1 >=0 ) {
                    index3 = myVector[i-1][j-1] + triangle[i][j];
                }
                myVector[i][j] = min(index1,index3);
            }
        }

        for(auto i : myVector[triangle.size()-1]) {
            cout << i << " ";
            result = min(result,i);
        }
        return result;
    }
};

