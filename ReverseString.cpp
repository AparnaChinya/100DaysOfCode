/*
 * Reverse String
  Go to Discuss
Write a function that takes a string as input and returns the string reversed.

Example 1:

Input: "hello"
Output: "olleh"
Example 2:

Input: "A man, a plan, a canal: Panama"
Output: "amanaP :lanac a ,nalp a ,nam A"
 */
class Solution {
public:
    string reverseString(string s) {
        int start = 0;
        int end = s.length() - 1;

        while(start < end) {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;

            //Increment and decrement inside the while loop instead of in the statement
            start++;
            end--;
        }
        return s;
    }
};