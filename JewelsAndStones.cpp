/*
771. Jewels and Stones
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in Sis a type of stone you have.  You want to know how many of the stones you have are also jewels.
The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".
Example 1:
Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:
Input: J = "z", S = "ZZ"
Output: 0
Note:
	• S and J will consist of letters and have length at most 50.
	• The characters in J are distinct.

From <https://leetcode.com/problems/jewels-and-stones/description/>
*/
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char,int> myMap;
        int result = 0;
        for(int i = 0; i < J.length(); i++){
            myMap[J[i]] = 1;
        }

        for(int j = 0; j < S.size(); j++) {
            if(myMap[S[j]] == 1) {
                result++;
            }
        }

        return result;
    }
};

