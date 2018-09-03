/* Reverse Words in a String

Given an input string, reverse the string word by word.
Example:  
Input: "the sky is blue",
Output: "blue is sky the".
Note:
	• A word is defined as a sequence of non-space characters.
	• Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
	• You need to reduce multiple spaces between two words to a single space in the reversed string.
Follow up: For C programmers, try to solve it in-place in O(1) space.

From <https://leetcode.com/explore/interview/card/microsoft/30/array-and-strings/166>

*/

class Solution {
public:
    void reverseWords(string &s) {

        reverse(s.begin(),s.end());
        int storeIndex = 0;

        for(int i = 0; i < s.size(); i++) {
            //From the starting position where the character is not space.
            if(s[i] != ' ') {
                //Similar to the counting problem.. store the characters in its right positions after adding the space
                if(storeIndex != 0) {
                    s[storeIndex++] = ' ';
                }
                //TO keep track of the first character which needs to be reversed
                int position = i;
                while(position < s.size() && s[position] != ' ') {

                    s[storeIndex++] = s[position++];
                }
                // After eliminating the extra spaces, reverse the word!
                reverse(s.begin() + storeIndex - (position - i), s.begin() + storeIndex);

                //Move to the next position where the words needs to be reverse and the space needs to be removed
                i = position;
            }
        }
        //erase the ending spaces
        s.erase(s.begin() + storeIndex, s.end());

    }
};

