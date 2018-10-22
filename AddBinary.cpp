/*
67. Add Binary
Given two binary strings, return their sum (also a binary string).
The input strings are both non-empty and contains only characters 1 or 0.
Example 1:
Input: a = "11", b = "1"
Output: "100"
Example 2:
Input: a = "1010", b = "1011"
Output: "10101"

From <https://leetcode.com/problems/add-binary/description/>

*/

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int i = a.size()-1;
        int j = b.size()-1;
        string result = "";

        while(carry == 1 || i >= 0 || j >= 0) {
            carry += i >= 0 ? a[i]-'0' : 0;
            i--;
            carry += j >= 0 ? b[j]-'0' : 0;
            j--;
            result = char(carry%2 + '0') + result;
            carry = carry/2;
        }

        return result;
    }
};

