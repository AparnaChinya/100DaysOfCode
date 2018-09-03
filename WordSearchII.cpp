/*
212. Word Search II
Given a 2D board and a list of words from the dictionary, find all words in the board.
Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
Example:
Input:
words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Output: ["eat","oath"]
Note:
You may assume that all inputs are consist of lowercase letters a-z.

From <https://leetcode.com/problems/word-search-ii/description/>
*/
class Solution {
public:
    class TrieNode {
    public:
        string entireWord;
        TrieNode *children[26];

    };
    TrieNode *root;

    void AddWordToTrie(string word) {
        TrieNode *crawl = root;

        for(int i=0; i < word.size(); i++) {
            if(crawl->children[word[i]-'a'] == NULL) {
                crawl->children[word[i]-'a'] = new TrieNode();
            }
            crawl = crawl->children[word[i]-'a'];
        }
        crawl->entireWord = word;
    }

    bool searchWords(string word) {
        TrieNode *crawl = root;

        for(int i = 0; i < word.size(); i++) {
            if(crawl->children[word[i]-'a'] == NULL) {
                return false;
            }
            crawl = crawl->children[word[i]-'a'];
        }
        return true;
    }

    void buildTrie(vector<string> &words) {
        for(int i = 0; i < words.size(); i++) {
            AddWordToTrie(words[i]);
        }
    }

    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *root, vector<string> &result) {
        char c = board[i][j];

        if(c == '#'  || root->children[c-'a'] == NULL) {
            return;
        }
        root = root->children[c-'a'];

        if(root->entireWord != "") {
            result.push_back(root->entireWord);
            root->entireWord = "";
            return;
        }
        board[i][j] = '#';
        if(i-1 >= 0) {
            dfs(board,i-1,j,root,result);
        }
        if(j-1 >= 0) {
            dfs(board,i,j-1,root,result);
        }
        if(i+1 < row) {
            dfs(board,i+1,j,root,result);
        }
        if(j+1 < column) {
            dfs(board,i,j+1,root,result);
        }
        board[i][j] = c;

    }

    int row ;
    int column;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        vector<string> result;

        //Build the Trie
        buildTrie(words);

        //Check if the trie works properly
        // cout << searchWords(words[1]);

        row = board.size();
        if(row == 0) {
            return result;
        }
        column = board[0].size();

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                dfs(board,i,j,root,result);
            }
        }

        return result;
    }
};

