/*
301. Remove Invalid Parentheses
DescriptionHintsSubmissionsDiscussSolution
Pick One

Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
Note: The input string may contain letters other than the parentheses ( and ).
Example 1:
Input: "()())()"
Output: ["()()()", "(())()"]
Example 2:
Input: "(a)())()"
Output: ["(a)()()", "(a())()"]
Example 3:
Input: ")("
Output: [""]

From <https://leetcode.com/problems/remove-invalid-parentheses/description/>

*/

class Solution {
public:
    bool validParenthesis(string temp) {
        int count = 0;
        for(int i = 0; i < temp.length(); i++) {
            if(temp[i] == '(') {
                count++;
            }
            if(temp[i] == ')') {
                count--;
            }
            if(count < 0) {
                return false;
            }
        }
        return count == 0;
    }

    bool parentheses(char temp) {
        return (temp == ')') || (temp == '(');
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        set<string> visited;
        queue<string> myQueue;

        myQueue.push(s);
        visited.insert(s);
        bool level = false;

        while(!myQueue.empty()) {
            auto temp = myQueue.front();
            myQueue.pop();

            if(validParenthesis(temp)) {
                result.push_back(temp);
                level = true;
            }
            if(level) {
                continue;
            }
            for(int i = 0; i < temp.length(); i++) {

                if (temp[i] != '(' && temp[i]!= ')') continue;

                string t = temp.substr(0,i) + temp.substr(i+1);
                if(visited.find(t) == visited.end()) {
                    visited.insert(t);
                    myQueue.push(t);
                }
            }

        }
        if(result.size() == 0) {
            result.push_back("");
            return result;
        }

        return result;
    }
};

