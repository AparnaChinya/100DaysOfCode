/*
221. Maximal Square
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
Example:
Input:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Output: 4

From <https://leetcode.com/problems/maximal-square/description/>


*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) {
            return 0;
        }
        vector<vector<int>> DP(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        int result = 0;

        for(int i = 1; i <= matrix.size(); i++) {
            for(int j = 1; j <= matrix[0].size(); j++) {
                if(matrix[i-1][j-1] == '1') {
                    DP[i][j] = min(min(DP[i-1][j],DP[i][j-1]),DP[i-1][j-1]) + 1;
                    result = max(result,DP[i][j]);
                }
            }
        }
        return result * result;
    }
};

