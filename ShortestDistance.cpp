/*
244. Shortest Word Distance II
Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list. Your method will be called repeatedly many times with different parameters. 
Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

From <https://leetcode.com/problems/shortest-word-distance-ii/description/>


*/
class WordDistance {
public:
    unordered_map<string,vector<int>> myMap;

    WordDistance(vector<string> words) {
        for(int i = 0; i < words.size(); i++) {
            myMap[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        auto l1 = myMap[word1];
        auto l2 = myMap[word2];
        int result = INT_MAX;
        int i = 0; int j = 0;

        while(i < l1.size() && j < l2.size()) {
            result = min(result, abs(l1[i]-l2[j]));
            if(l1[i] < l2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return result;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */

