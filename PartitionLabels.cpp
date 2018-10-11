/*
763. Partition Labels
A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.
Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:
	1. S will have length in range [1, 500].
	2. S will consist of lowercase letters ('a' to 'z') only.


From <https://leetcode.com/problems/partition-labels/description/#_=_>
*/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> charIndex(26,0);
        int j = INT_MIN;
        vector<int> answer;
        int anchor = 0;

        //Put lastindex for each character
        for(int i = 0; i < S.length(); i++) {
            charIndex[S[i]-'a'] = i;
        }

        //keep track of anchor and minimum splits
        for(int i = 0; i < S.length(); i++) {
            j = max(j,charIndex[S[i]-'a']);
            if(i == j) {
                answer.push_back(i - anchor + 1);
                anchor = i + 1;
            }
        }
        return answer;
    }
};

