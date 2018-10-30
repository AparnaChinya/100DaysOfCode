/*
224. Basic Calculator
Implement a basic calculator to evaluate a simple expression string.
The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
Example 1:
Input: "1 + 1"
Output: 2
Example 2:
Input: " 2-1 + 2 "
Output: 3
Example 3:
Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23
Note:
	• You may assume that the given expression is always valid.
	• Do not use the eval built-in library function.

From <https://leetcode.com/problems/basic-calculator/description/>


*/

class Solution {
public:
    int precedence(char s) {
        if(s == '+' || s == '-') {
            return 1;
        } else if(s == '*' || s == '/') {
            return 2;
        } else {
            return 0;
        }
    }


    int applyOperator(int a, int b, char op) {
        switch(op) {
            case '+' : return a+b;
            case '-' : return a-b;
            case '*' : return a*b;
            case '/' : return a/b;
        }
    }

    int calculate(string s) {
        stack<int> numbers;
        stack<char> operators;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') {
                continue;
            } else if(s[i] == '(') {
                operators.push(s[i]);

            } else if(s[i] == ')') {
                while(!operators.empty() && operators.top() != '(') {
                    int val2 = numbers.top(); numbers.pop();
                    int val1 = numbers.top(); numbers.pop();

                    char op = operators.top(); operators.pop();
                    numbers.push(applyOperator(val1,val2,op));
                }
                operators.pop();

            } else if(isdigit(s[i])) {
                int num = 0;
                while(i < s.length() && isdigit(s[i])) {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                i--;
                numbers.push(num);
            } else {
                while(!operators.empty() && precedence(operators.top()) >= precedence(s[i])) {
                    int val2 = numbers.top(); numbers.pop();
                    int val1 = numbers.top(); numbers.pop();

                    char op = operators.top(); operators.pop();
                    numbers.push(applyOperator(val1,val2,op));
                }
                operators.push(s[i]);
            }

        }

        while(!operators.empty()) {
            int val2 = numbers.top(); numbers.pop();
            int val1 = numbers.top(); numbers.pop();

            char op = operators.top(); operators.pop();
            numbers.push(applyOperator(val1,val2,op));
        }

        return numbers.top();
    }
};
