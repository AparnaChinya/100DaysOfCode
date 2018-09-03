/*1. Container With Most Water
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container and n is at least 2.
 

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
 
Example:
Input: [1,8,6,2,5,4,8,3,7]
Output: 49

From <https://leetcode.com/problems/container-with-most-water/description/>

*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int maxArea = INT_MIN;
        //Kind of like binary search.. keep moving towards the higher line when comparing start and end points
        while(start <= end) {
            maxArea = max(maxArea, min(height[start],height[end]) * (end-start));
            if(height[start] < height[end]) {
                start++;
            } else {
                end--;
            }
        }
        return maxArea;
    }
};

