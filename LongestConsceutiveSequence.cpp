/*
128. Longest Consecutive Sequence
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
Your algorithm should run in O(n) complexity.
Example:
Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

From <https://leetcode.com/problems/longest-consecutive-sequence/description/>

*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }

        set<int> mySet;
        int longestStreak = INT_MIN;

        //Put all the numbers into a set
        for(auto item : nums) {
            mySet.insert(item);
        }

        //For all the numbers
        for(int i = 0; i < nums.size(); i++) {
            int currentStreak = 1;
            //Check if number - 1 is in the set, if its not there Only then procees
            if(mySet.find(nums[i]-1) == mySet.end()) {
                int currentNum = nums[i];
                cout << currentNum << endl;
                //As long as you can find number + 1 increment the streakcount
                while(mySet.find(currentNum+1) != mySet.end()) {
                    currentStreak++;
                    currentNum++;
                }
            }
            longestStreak = max(longestStreak, currentStreak);
        }

        return longestStreak;
    }
};

