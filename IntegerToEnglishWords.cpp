/*
273. Integer to English Words
DescriptionHintsSubmissionsDiscussSolution
Pick One

Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.
Example 1:
Input: 123
Output: "One Hundred Twenty Three"
Example 2:
Input: 12345
Output: "Twelve Thousand Three Hundred Forty Five"

From <https://leetcode.com/problems/integer-to-english-words/description/>

*/
class Solution {
public:
    //Less than 10
    string lessThan10[11] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    //Less than 20 from 10
    string lessThan20[11] = {"Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen","Twenty"};

    //Less than 100 from 10
    string lessThan100[10] = {"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

    string helper(int num) {
        string result = "";
        if(num < 10) {
            result = lessThan10[num];
        }
        else if(num < 20) {
            result = lessThan20[num-10];
        }
        else if(num < 100) {
            result = lessThan100[num/10] + " " + helper(num%10);
        }
        else if(num < 1000) {
            result = lessThan10[num/100] + " Hundred " + helper(num % 100);
        }
        else if(num < 1000000) {
            result = helper(num/1000) + " Thousand " + helper(num % 1000);
        }
        else if(num < 1000000000) {
            result = helper(num/1000000) + " Million " + helper(num % 1000000);
        }
        else result = helper(num/1000000000) + " Billion " + helper(num % 1000000000);

        if(result[result.size()-1] == ' ') {
            return result.substr(0,result.size()-1);
        }
        return result;
    }

    string numberToWords(int num) {
        if(num == 0) {
            return "Zero";
        }
        string s = helper(num);
        if(s[s.size()-1] == ' ') {
            return s.substr(0,s.size()-1);
        }
        return s;
    }
};


