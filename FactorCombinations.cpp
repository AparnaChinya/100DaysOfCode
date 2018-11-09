/*
254. Factor Combinations
Numbers can be regarded as product of its factors. For example,
8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.
Note:
	1. You may assume that n is always positive.
	2. Factors should be greater than 1 and less than n.
Example 1:
Input: 1
Output: []
Example 2:
Input: 37
Output:[]
Example 3:
Input: 12
Output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
Example 4:
Input: 32
Output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]

From <https://leetcode.com/problems/factor-combinations/description/>
*/

class Solution {
public:
    vector<vector<int>> result;

    void dfs(int n, int start, vector<int> path) {
        for(int i = start; i <= sqrt(n); i++) {
            if(n % i == 0) {
                vector<int> newPath = path;
                newPath.push_back(i);
                dfs(n/i,i,newPath);
                newPath.push_back(n/i);
                result.push_back(newPath);
            }
        }
    }

    vector<vector<int>> getFactors(int n) {
        vector<int> path;
        dfs(n,2,path);
        return result;
    }
};

