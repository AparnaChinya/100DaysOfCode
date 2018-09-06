/* 84. Largest Rectangle in Histogram
DescriptionHintsSubmissionsDiscussSolution
Pick One

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

From <https://leetcode.com/problems/largest-rectangle-in-histogram/description/>
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int result = 0;
        heights.push_back(0);
        stack<int> index;

        for(int i = 0; i < heights.size(); i++)
        {
            while(index.size() > 0 && heights[index.top()] >= heights[i])
            {
                int h = heights[index.top()];
                index.pop();

                int sidx = index.size() > 0 ? index.top() : -1;
                result = max(result, h * (i-sidx-1));
            }
            index.push(i);
        }

        return result;
    }
};

