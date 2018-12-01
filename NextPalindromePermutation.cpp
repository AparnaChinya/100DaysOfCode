/*66. Palindrome Permutation
DescriptionHintsSubmissionsDiscussSolution
        Pick One

        Given a string, determine if a permutation of the string could form a palindrome.
Example 1:
Input: "code"
Output: false
Example 2:
Input: "aab"
Output: true
Example 3:
Input: "carerac"
Output: true


From <https://leetcode.com/problems/palindrome-permutation/description/>
*/

class Solution {
public:

    bool canPermutePalindrome(string s) {
        bitset<256> mySet;

        for(int i = 0; i < s.length(); i++) {
            mySet.flip(s[i]);
        }

        return mySet.count() < 2;
    }
};

