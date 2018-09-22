/*
161. One Edit Distance
Given two strings s and t, determine if they are both one edit distance apart.
Note: 
There are 3 possiblities to satisify one edit distance apart:
	1. Insert a character into s to get t
	2. Delete a character from s to get t
	3. Replace a character of s to get t
Example 1:
Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.
Example 2:
Input: s = "cab", t = "ad"
Output: false
Explanation: We cannot get t from s by only one step.
Example 3:
Input: s = "1203", t = "1213"
Output: true
Explanation: We can replace '0' with '1' to get t.

From <https://leetcode.com/problems/one-edit-distance/description/>
*/
//approach1
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int sLength = s.length();
        int tLength = t. length();

        if(abs(sLength-tLength) > 1) {
            return false;
        }

        int i = 0;
        int j = 0;
        int count = 0;

        while(i < sLength && j < tLength) {
            if(s[i] != t[j]) {
                count++;
                if(count > 1) {
                    return false;
                }
                if(sLength > tLength) {
                    i++;
                } else if(sLength < tLength) {
                    j++;
                } else {
                    i++;
                    j++;
                }
            } else {
                i++;
                j++;
            }
        }

        if(i < sLength || j < tLength) {
            count++;
        }

        return count == 1;
    }
};

//Approach2

class Solution2 {
public:
    bool isOneEditDistance(string s, string t) {
        if(s==t) {
            return false;
        }
        vector<vector<int>> myMatrix(2,vector<int>(t.length()+1,0));
        bool bi = false;

        for(int i = 0; i <= s.length(); i++) {
            bi = i & 1;
            cout << bi;
            for(int j = 0; j <= t.length(); j++) {
                if(i == 0) {
                    myMatrix[bi][j] = j;
                } else if(j == 0) {
                    myMatrix[bi][j] = i;
                } else if(s[i-1] == t[j-1]) {
                    myMatrix[bi][j] = myMatrix[1-bi][j-1];
                } else {
                    myMatrix[bi][j] = 1 + min(myMatrix[1-bi][j],min(myMatrix[bi][j-1],myMatrix[1-bi][j-1]));

                }
            }
        }
        return myMatrix[bi][t.length()] > 1 ? false : true;

    }
};

