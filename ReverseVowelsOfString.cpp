/*
345. Reverse Vowels of a String
Write a function that takes a string as input and reverse only the vowels of a string.
Example 1:
Input: "hello"
Output: "holle"
Example 2:
Input: "leetcode"
Output: "leotcede"
Note:
The vowels does not include the letter "y".
 

From <https://leetcode.com/problems/reverse-vowels-of-a-string/description/>
*/

class Solution {
public:
    string reverseVowels(string s) {
        set<char> mySet = {'a','e','i','o','u','A','E','I','O','U'};

        int left = 0; int right = s.length()-1;

        while(left < right) {
            while(left < right && mySet.find(s[left]) == mySet.end()) {
                left++;
            }
            while(right >= left && mySet.find(s[right]) == mySet.end()) {
                right--;
            }
            cout << s[left] << s[right] << endl;
            if(mySet.find(s[left]) != mySet.end() && mySet.find(s[right]) != mySet.end()) {
                swap(s[left],s[right]);
                left++; right--;
            }

        }

        return s;
    }
};

