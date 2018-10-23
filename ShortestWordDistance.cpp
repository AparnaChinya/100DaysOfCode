/*
 * 243. Shortest Word Distance
DescriptionHintsSubmissionsDiscussSolution
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.


 */
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int index1 = -1;
        int index2 = -1;
        int result = INT_MAX;

        for(int i = 0; i < words.size(); i++) {
            if(words[i] == word1) {
                index1 = i;
            }
            if(words[i] == word2) {
                index2 = i;
            }

            if(index1 != -1 && index2 != -1) {
                result = min(result,abs(index1-index2));
            }
        }
        return result;

    }
};