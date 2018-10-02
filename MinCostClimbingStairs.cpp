/*
746. Min Cost Climbing Stairs
On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.
Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
Note:
	1. cost will have a length in the range [2, 1000].
	2. Every cost[i] will be an integer in the range [0, 999].

From <https://leetcode.com/problems/min-cost-climbing-stairs/description/>

*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int step1 = 0;
        int step2 = 0;

        for(int i = cost.size()-1; i >= 0; i--) {
            int temp = cost[i] + min(step1,step2);
            //update step 2 to be step 1
            step2 = step1;
            //update step 1 to be the cost of the current step plus min if the previous 2 steps
            step1 = temp;
        }

        return min(step1,step2);
    }
};

