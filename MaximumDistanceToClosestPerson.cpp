/*
849. Maximize Distance to Closest Person
In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty. 
There is at least one empty seat, and at least one person sitting.
Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 
Return that maximum distance to closest person.
Example 1:
Input: [1,0,0,0,1,0,1]
Output: 2
Explanation:
If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
Example 2:
Input: [1,0,0,0]
Output: 3
Explanation:
If Alex sits in the last seat, the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.
Note:
	1. 1 <= seats.length <= 20000
	2. seats contains only 0s or 1s, at least one 0, and at least one 1.

From <https://leetcode.com/problems/maximize-distance-to-closest-person/description/>
*/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int result = INT_MIN;
        int front = 0;
        int back = 0;

        int left = 0 ; int right = seats.size()-1;
        while(seats[left++] == 0) {
            front++;
        }
        while(seats[right--] == 0) {
            back++;
        }

        for(int i = 0; i < seats.size(); i++) {
            int temp = 0;
            while(seats[i] == 0) {
                i++; temp++;
            }
            result = max(result,temp);
        }

        return max(max(front,back),(result+1)/2);
    }
};

