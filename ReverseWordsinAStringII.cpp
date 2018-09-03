/* Reverse Words in a String II
  Go to Discuss
Given an input string , reverse the string word by word. 
Example:
Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
Note: 
	• A word is defined as a sequence of non-space characters.
	• The input string does not contain leading or trailing spaces.
	• The words are always separated by a single space.
Follow up: Could you do it in-place without allocating extra space?

From <https://leetcode.com/explore/interview/card/microsoft/30/array-and-strings/213/>
*/

class Solution {
public:
    void reverseWords(vector<char>& str) {
        int start = 0;
        int end = str.size() - 1;

        while(start < end) {
            char temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            start ++;
            end--;
        }

        for(int i = 0 ; i < str.size(); i++) {
            int temp = i;
            while(str[i] != ' ' && i < str.size()) {
                i++;
            }
            reverse(str.begin()+temp, str.begin() + i);
        }

    }
};

