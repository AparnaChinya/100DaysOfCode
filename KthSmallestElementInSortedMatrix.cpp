/*
378. Kth Smallest Element in a Sorted Matrix
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.
Example:
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,
return 13.
Note: 
You may assume k is always valid, 1 ≤ k ≤ n2.

From <https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/>

*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> nums;
        priority_queue<int> maxHeap;

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                nums.push_back(matrix[i][j]);
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            maxHeap.push(nums[i]);
            if(maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
};

