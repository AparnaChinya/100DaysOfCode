/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining. 
For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. 

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. 
From <https://leetcode.com/problems/trapping-rain-water/> 
*/

class Solution {
public:
   int trap(vector<int>& height) {

		int number = height.size();

       if(!number) return 0;
       
		int *Left = new int[number];
		int *Right = new int[number];

       
		Left[0] = height[0];
		Right[number-1] = height[number-1];

		for (int i = 1; i<number; i++)
		{
			Left[i] = max(Left[i - 1], height[i]);
		}

		for (int j = number - 2; j >= 0; j--)
		{
			Right[j] = max(Right[j + 1], height[j]);
		}

		int sum = 0;
		for (int k = 1; k<number; k++)
		{
			sum += min(Left[k], Right[k]) - height[k];
		}

		return (sum);
	}
};

