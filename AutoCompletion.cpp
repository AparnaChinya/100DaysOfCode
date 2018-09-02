/*
Design Search Autocomplete System

From <https://leetcode.com/problems/design-search-autocomplete-system/description/>
 */
class AutocompleteSystem {
public:
    class TrieNode{
    public:
        char c;
        unordered_map<char,TrieNode*> children;
        unordered_map<string,int> counts;
        bool isLeaf;

        TrieNode(char c) {
            isLeaf = false;
            this->c = c;
        }
    };
    TrieNode *root;

    void add(string sentence, int times) {
        TrieNode *crawl = root;
        for(char c : sentence) {
            if(crawl->children[c] == nullptr) {
                crawl->children[c] = new TrieNode(c);
            }
            crawl = crawl->children[c];
            crawl->counts[sentence] += times;
        }
        crawl->isLeaf = true;
    }


    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        prefix = "";
        root = new TrieNode(' ');
        for(int i = 0; i < sentences.size(); i++) {
            add(sentences[i],times[i]);
        }
    }
    string prefix;
    struct compare {
        bool operator()(const pair<string, int>& lhs, const pair<string, int>&rhs) {
            return lhs.second < rhs.second || (lhs.second == rhs.second && lhs.first > rhs.first);
        }
    };

    vector<string> input(char c) {
        if(c == '#') {
            add(prefix,1);
            prefix = "";
            return {};
        }

        prefix += c;
        TrieNode *current = root;
        for(auto ch : prefix) {
            if(current->children[ch] == nullptr) {
                return {};
            }
            current = current->children[ch];
        }

        priority_queue<pair<string,int>,vector<pair<string,int>>,compare> q;
        for(auto &it : current->counts) {
            q.push(it);
        }

        vector<string> result;
        int k = 3;
        while(!q.empty() && k-- > 0){
            result.push_back(q.top().first);
            q.pop();
        }
        return result;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */

