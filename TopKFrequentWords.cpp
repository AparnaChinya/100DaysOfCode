/*
692. Top K Frequent Words
Given a non-empty list of words, return the k most frequent elements.
Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.
Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
	1. You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
	2. Input words contain only lowercase letters.
Follow up:
	1. Try to solve it in O(n log k) time and O(n) extra space.


From <https://leetcode.com/problems/top-k-frequent-words/description/>
*/
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //Custom comparator function for priority queue
        struct compare {
            bool operator () (pair<string,int> a, pair<string,int> b) {
                return a.second < b.second || (a.second == b.second && a.first > b.first);
            }
        };

        map<string,int> myMap;
        priority_queue<pair<string,int>,vector<pair<string,int>>,compare> myQueue;
        vector<string> result;

        //put all words into ordered map
        for(int i = 0; i < words.size(); i++) {
            myMap[words[i]]++;
        }

        //Use comparotr function to check the values of the map
        for(auto item : myMap) {
            myQueue.push(make_pair(item.first,item.second));
        }

        //Output the top k elements
        while(!myQueue.empty() && k) {
            k--;
            result.push_back(myQueue.top().first);
            myQueue.pop();
        }
        return result;
    }
};
