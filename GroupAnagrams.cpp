/ * Group Anagrams

Given an array of strings, group anagrams together.
Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
["ate","eat","tea"],
["nat","tan"],
["bat"]
]
Note:
• All inputs will be in lowercase.
• The order of your output does not matter.

From <https://leetcode.com/explore/interview/card/microsoft/30/array-and-strings/200/>
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;

        unordered_map<string,vector<string>> myMap;

        //Sort each string and put it as a key in the map with the list of same anagrams as its values
        for(string myString : strs) {
            string temp = myString;
            sort(myString.begin(),myString.end());
            myMap[myString].push_back(temp);
        }
        //return all the values in the map grouped together
        for(auto a = myMap.begin(); a != myMap.end(); a++) {
            result.push_back(a->second);
        }

        return result;
    }
};


