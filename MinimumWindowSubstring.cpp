/*
Minimum Window Substring
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
Example:
Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:
	• If there is no such window in S that covers all characters in T, return the empty string "".
	• If there is such window, you are guaranteed that there will always be only one unique minimum window in S.

From <https://leetcode.com/problems/minimum-window-substring/description/>
*/
class Solution {
public:
    string minWindow(string s, string t) {

        if(s.length() < t.length()) {
            return "";
        }

        //Maintain two maps
        unordered_map<char,int> mapOfS;
        unordered_map<char,int> mapOfT;

        for(char ch:t) {
            mapOfT[ch]++;
        }

        int start = 0; int minLength = INT_MAX;
        int count = 0; int startIndex = 0;

        for(int i = 0; i < s.length(); i++) {
            mapOfS[s[i]]++;
            //If the strings character matches the patterns character
            if(mapOfT[s[i]] != 0 && mapOfS[s[i]] <= mapOfT[s[i]]) {
                count++;
            }

            //Move the window
            if(count == t.length()) {

                //IMPORTANT: While unwanted character just move, if wanted character in T, then decrement the count and move forward
                while(mapOfT[s[start]] == 0 || mapOfS[s[start]] > mapOfT[s[start]]) {
                    if(mapOfS[s[start]] > mapOfT[s[start]]) {
                        mapOfS[s[start]]--;
                    }
                    start++;
                }

                //Update the minWindowLength
                int minWindowsLength = i - start + 1;
                if(minWindowsLength < minLength) {
                    minLength = minWindowsLength;
                    startIndex = start;
                }
            }

        }

        return minLength == INT_MAX ? "" : s.substr(startIndex, minLength);

    }
};

