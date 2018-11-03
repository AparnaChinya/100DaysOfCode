/*
739. Daily Temperatures
Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.
For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100]

From <https://leetcode.com/problems/daily-temperatures/description/>

*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result(T.size());
        stack<int> myStack;

        for(int i = T.size()-1; i >=0; i--) {
            while(!myStack.empty() && T[i] >= T[myStack.top()]) {
                myStack.pop();
            }
            result[i] = (myStack.empty() == true) ? 0 : myStack.top() - i;
            myStack.push(i);

        }
        return result;
    }
};

