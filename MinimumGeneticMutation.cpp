/*
433. Minimum Genetic Mutation
A gene string can be represented by an 8-character long string, with choices from "A", "C", "G", "T".
Suppose we need to investigate about a mutation (mutation from "start" to "end"), where ONE mutation is defined as ONE single character changed in the gene string.
For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.
Also, there is a given gene "bank", which records all the valid gene mutations. A gene must be in the bank to make it a valid gene string.
Now, given 3 things - start, end, bank, your task is to determine what is the minimum number of mutations needed to mutate from "start" to "end". If there is no such a mutation, return -1.
Note:
	1. Starting point is assumed to be valid, so it might not be included in the bank.
	2. If multiple mutations are needed, all mutations during in the sequence must be valid.
	3. You may assume start and end string is not the same.

From <https://leetcode.com/problems/minimum-genetic-mutation/description/>

*/

class Solution {
public:
    void addAdjacentWord(string word,unordered_set<string> &wordDict,queue<string> &myQueue) {
        wordDict.erase(word);
        word = word.c_str();
        for(int i = 0; i < word.length(); i++) {
            char letter = word[i];

            for(char j : "ACGT") {
                word[i] = j;
                if(wordDict.find(word) != wordDict.end()) {
                    cout << word << " " ;
                    myQueue.push(word);
                    wordDict.erase(word);
                }
            }
            word[i] = letter;
        }
    }

    int minMutation(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict(wordList.begin(),wordList.end());

        if(wordDict.find(endWord) == wordDict.end()) {
            return -1;
        }

        int dist = 1;
        queue<string> myQueue;
        addAdjacentWord(beginWord,wordDict,myQueue);

        while(!myQueue.empty()) {
            int size = myQueue.size();
            for(int i = 0; i < size; i++) {
                string temp = myQueue.front();
                myQueue.pop();
                if(temp == endWord) {
                    return dist;
                }
                addAdjacentWord(temp,wordDict,myQueue);
            }
            dist++;
        }
        return -1;
    }
};

