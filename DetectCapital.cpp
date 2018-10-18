/*
520. Detect Capital
Given a word, you need to judge whether the usage of capitals in it is right or not.
We define the usage of capitals in a word to be right when one of the following cases holds:
	1. All letters in this word are capitals, like "USA".
	2. All letters in this word are not capitals, like "leetcode".
	3. Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False
Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.

From <https://leetcode.com/problems/detect-capital/description/>

*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() == 0) {
            return true;
        }
        bool isNoun = false;

        if(word.size() == 1) {
            return true;
        }

        if(isupper(word[0])){
            isNoun = true;
        }

        bool allCap = true;
        bool allSmall = true;

        for(int i = 1; i < word.length(); i++) {
            bool t = isupper(word[i]);

            allCap = allCap && t;
            allSmall = allSmall && !t;

            if(allCap == allSmall) {
                return false;
            }
        }

        if(allCap && !isNoun) {
            return false;
        }

        return true;
    }
};

