/* 85. Maximal Rectangle
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
Example:
Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6

From <https://leetcode.com/problems/maximal-rectangle/description/>
*/

class Solution {
public:
    int getMaxHistogram(vector<int> matrix) {
        int answer = 0;
        stack<int> myStack;
        matrix.push_back(0);
        //myStack.push(0);
        for(int i = 0; i < matrix.size(); i++) {
            while(!myStack.empty() && matrix[i] <= matrix[myStack.top()]) {
                int h = matrix[myStack.top()];
                myStack.pop();
                int sidex = myStack.size() > 0 ? myStack.top() : -1;
                answer = max(answer,h * (i - sidex -1));
            }
            myStack.push(i);
        }
        cout << "A " << answer << endl;
        return answer;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) {
            return 0;
        }

        int area = INT_MIN;
        vector<int> firstRow;

        for(int j = 0; j < matrix[0].size(); j++) {
            firstRow.push_back(matrix[0][j] - '0');
            cout << firstRow[j] << " ";
        }
        cout <<endl;

        area = getMaxHistogram(firstRow);

        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == '0') {
                    firstRow[j] = 0;
                } else {
                    firstRow[j] += matrix[i][j]-'0';
                }
                cout << firstRow[j] << " ";
            }
            area = max(area,getMaxHistogram(firstRow));
            cout << endl;
        }

        return area;
    }
};

