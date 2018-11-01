/*
97. Interleaving String
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
Example 1:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false

From <https://leetcode.com/problems/interleaving-string/description/>


*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) {
            return false;
        }
        vector<vector<bool>> DP(s1.length()+1,vector<bool>(s2.length()+1,false));

        for(int i = 0; i <= s1.length(); i++) {
            for(int j = 0; j <= s2.length(); j++) {
                if(i==0 && j== 0) {
                    DP[i][j] = true;
                } else if(i == 0) {
                    DP[i][j] = (DP[i][j-1] && s2[j-1] == s3[i+j-1]);
                } else if(j==0) {
                    DP[i][j] = (DP[i-1][j] && s1[i-1] == s3[i+j-1]);
                } else {
                    DP[i][j] = (DP[i][j-1] && s2[j-1] == s3[i+j-1]) || (DP[i-1][j] && s1[i-1] == s3[i+j-1]);
                }
            }
        }
        return DP[s1.size()][s2.size()];
    }
};

