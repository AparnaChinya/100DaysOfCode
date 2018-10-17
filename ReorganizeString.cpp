/*
767. Reorganize String
Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.
If possible, output any possible result.  If not possible, return the empty string.
Example 1:
Input: S = "aab"
Output: "aba"
Example 2:
Input: S = "aaab"
Output: ""
Note:
	• S will consist of lowercase letters and have length in range [1, 500].

From <https://leetcode.com/problems/reorganize-string/description/>

*/

class Solution {
public:
    struct compare {
        bool operator () (pair<int,char> &a, pair<int,char> &b) {
            return (a.first < b.first) || (a.second > b.second && a.first == b.first);
        }
    };

    string reorganizeString(string S) {
        vector<int> myMap(26,0);
        priority_queue< pair<int,char>, vector<pair<int,char>>, compare> myQueue;
        string result = "";

        for(int i = 0; i < S.length(); i++) {
            myMap[S[i]-'a'] += 1;
        }

        for(int i = 0; i < 26; i++) {
            if(myMap[i] > (S.length()+1)/2 ) {
                return "";
            }

            if(myMap[i] > 0) {
                char c = (char)(i+'a');
                //cout << c << myMap[i] << " ";
                myQueue.push(make_pair(myMap[i],c));
            }
        }

        while(myQueue.size() >= 2) {
            auto one = myQueue.top(); myQueue.pop();
            auto two = myQueue.top(); myQueue.pop();
            cout << one.first << " " << two.first << endl;

            result += one.second ;
            result += two.second;

            one.first -= 1;
            two.first -= 1;

            if(one.first > 0) myQueue.push(one);
            if(two.first > 0) myQueue.push(two);
        }

        while(myQueue.size() >= 1) {
            result += myQueue.top().second;
            myQueue.pop();
        }

        return result;
    }
};

