/*
165. Compare Version Numbers
Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
Example 1:
Input: version1 = "0.1", version2 = "1.1"
Output: -1
Example 2:
Input: version1 = "1.0.1", version2 = "1"
Output: 1
Example 3:
Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1

From <https://leetcode.com/problems/compare-version-numbers/description/>


*/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int num1 = 0;
        int num2 = 0;
        int size1 = version1.size();
        int size2 = version2.size();
        int i = 0;
        int j= 0;

        //Convert both the strings to numbers one by one. (that is for each number before point and compare)
        while(i < size1 || j < size2) {
            while(i < size1 && version1[i] != '.') {
                num1 = num1 * 10 + version1[i]-'0';
                i++;

            }
            while(j < size2 && version2[j] != '.') {
                num2 = num2 * 10 + version2[j]-'0';
                j++;

            }
            if(num1 > num2) {
                return 1;
            } else if(num1 < num2) {
                return -1;
            }
            //Reset and compare the next numbers afer point
            num1 = 0; num2 = 0; i++; j++;

        }
        return 0;
    }
};

