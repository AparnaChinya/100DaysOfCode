/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
You have the following 3 operations permitted on a word:
	1. Insert a character
	2. Delete a character
	3. Replace a character
Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

From <https://leetcode.com/problems/edit-distance/description/>

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
                //Remembber the Phi and allocate j when i == 0 and vice versa
                if(i==0) {
                    DP[i][j] = j;
                }
                else if(j==0) {
                    DP[i][j] = i;
                }
                else if(word1[i-1] == word2[j-1]) {
                    DP[i][j] = DP[i-1][j-1];
                } else {
                    //Remove / add / edit
                    DP[i][j] = 1 + min(DP[i-1][j-1], min(DP[i-1][j],DP[i][j-1]));
                }
            }
        }
        return DP[m][n];
    }
};

