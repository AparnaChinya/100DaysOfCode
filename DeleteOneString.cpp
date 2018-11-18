/*
583. Delete Operation for Two Strings
Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.
Example 1:
Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Note:
	1. The length of given words won't exceed 500.
	2. Characters in given words can only be lower-case letters.

From <https://leetcode.com/problems/delete-operation-for-two-strings/description/>

*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        if(m == 0) {
            return n;
        }
        if(n == 0) {
            return m;
        }
        vector<vector<int>> DP(m+1,vector<int>(n+1,0));

        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                if(i==0) {
                    DP[i][j] = j;
                }
                else if(j==0) {
                    DP[i][j] = i;
                }
                else if(word1[i-1] == word2[j-1]) {
                    DP[i][j] = DP[i-1][j-1];
                } else {
                    DP[i][j] = 1 + min(DP[i-1][j],DP[i][j-1]);
                }
            }
        }

        // for(int i = 0; i < DP.size(); i++) {
        //     for(int j = 0; j < DP[0].size(); j++) {
        //         cout << DP[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return DP[m][n];
    }
};

