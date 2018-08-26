/* Sliding Window Maximum
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.
Example:
Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Note: 
You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.
Follow up:
Could you solve it in linear time?

From <https://leetcode.com/problems/sliding-window-maximum/description/>
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> myQueue;
        vector<int> result;
        int i;
        //USE DEQUEUE
        if(nums.size() == 0) {
            return result;
        }
        // FRONT OF THE QUEUE ALWAYS CONTAINS MAX ELEMENT
        for(i = 0; i < k; i++) {
            while(!myQueue.empty() && nums[i] >= nums[myQueue.back()]) {
                cout<< nums[myQueue.back()] << " " << nums[i];
                myQueue.pop_back();
            }
            //Push the index of all the elements on to the queue.
            myQueue.push_back(i);
        }

        //REst of the elements indexed greater than K
        for(; i < nums.size(); i++) {
            result.push_back(nums[myQueue.front()]);

            while(!myQueue.empty() && nums[myQueue.back()] <= nums[i]) {
                myQueue.pop_back();
            }
            while(!myQueue.empty() && myQueue.front() <= i-k) {
                myQueue.pop_front();
            }
            myQueue.push_back(i);
        }
        result.push_back(nums[myQueue.front()]);

        return result;
    }
};

