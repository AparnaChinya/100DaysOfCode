/*
422. Valid Word Square
Given a sequence of words, check whether it forms a valid word square.
A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).
Note:
	1. The number of words given is at least 1 and does not exceed 500.
	2. Word length will be at least 1 and does not exceed 500.
	3. Each word contains only lowercase English alphabet a-z.
Example 1:
Input:
[
  "abcd",
  "bnrt",
  "crmy",
  "dtye"
]
Output:
true
Explanation:
The first row and first column both read "abcd".
The second row and second column both read "bnrt".
The third row and third column both read "crmy".
The fourth row and fourth column both read "dtye".
Therefore, it is a valid word square.

From <https://leetcode.com/problems/valid-word-square/description/>

*/

class Solution {
public:
    bool validWordSquare(vector<string>& matrix) {
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(j >= matrix.size() || i >= matrix[j].size() || matrix[i][j] != matrix[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }
};

