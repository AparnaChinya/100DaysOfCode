/* Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
Example:
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

From <https://leetcode.com/explore/interview/card/microsoft/30/array-and-strings/211/>
*/
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0) {
            return 0;
        }
        vector<int> Left(height.size());
        vector<int> Right(height.size());

        Left[0] = height[0];
        Right[height.size()-1] = height[height.size()-1] ;

        for(int i = 1; i < height.size(); i++) {
            Left[i] = max(Left[i-1],height[i]);
        }
        for(int i = height.size()-2; i >= 0; i--) {
            Right[i] = max(Right[i+1],height[i]);
        }
        int result = 0;
        for(int i = 0; i < height.size(); i++) {
            result += min(Right[i],Left[i]) - height[i];
        }
        return result;
    }
};

