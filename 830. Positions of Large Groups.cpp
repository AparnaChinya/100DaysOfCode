/*
830. Positions of Large Groups
In a string S of lowercase letters, these letters form consecutive groups of the same character.
For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".
Call a group large if it has 3 or more characters.  We would like the starting and ending positions of every large group.
The final answer should be in lexicographic order.
 
Example 1:
Input: "abbxxxxzzy"
Output: [[3,6]]
Explanation: "xxxx" is the single large group with starting  3 and ending positions 6.
Example 2:
Input: "abc"
Output: []
Explanation: We have "a","b" and "c" but no large group.
Example 3:
Input: "abcdddeeeeaabbbcd"
Output: [[3,5],[6,9],[12,14]]
 
Note:  1 <= S.length <= 1000

From <https://leetcode.com/problems/positions-of-large-groups/description/>
*/

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> result;

        for(int i = 0; i < S.size()-1; i++) {
            int temp = i;
            int count = 1;
            while(S[i] == S[i+1]) {
                i++; count++;
            }
            cout << S[i] << endl;
            if(count >= 3) {
                result.push_back({temp,i});
            }

        }
        return result;
    }
};

