/*

451. Sort Characters By Frequency
Given a string, sort it in decreasing order based on the frequency of characters.
Example 1:
Input:
"tree"
Output:
"eert"
Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:
Input:
"cccaaa"
Output:
"cccaaa"
Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:
Input:
"Aabb"
Output:
"bbAa"
Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

From <https://leetcode.com/problems/sort-characters-by-frequency/description/>


*/

class Solution {
public:
    struct compare{
        bool operator()(pair<int,char> a, pair<int,char> b) {
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        }
    };

    string frequencySort(string s) {
        priority_queue<pair<int,char>,vector<pair<int,char>>,compare> myQueue;
        unordered_map<char,int> myMap;
        string result = "";

        for(int i = 0; i < s.length(); i++) {
            myMap[s[i]]++;
        }

        for(auto i : myMap) {
            myQueue.push(make_pair(i.second,i.first));
        }

        while(!myQueue.empty()) {
            int index = myQueue.top().first;
            int ch = myQueue.top().second;

            for(int i = 0; i < index; i++) {
                result += ch;
            }

            myQueue.pop();
        }

        return result;
    }
};

