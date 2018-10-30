/*
163. Missing Ranges
Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.
Example:
Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
Output: ["2", "4->49", "51->74", "76->99"]

From <https://leetcode.com/problems/missing-ranges/description/>


*/

class Solution {
public:
    string getRange(int start, int end) {
        return (start==end) ? to_string(start) : (to_string(start) + "->" + to_string(end));
    }

    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        long int previous = (long)lower - 1;
        vector<string> result;

        if(nums.size()<=0)
        {
            result.push_back(getRange(lower,upper));
            return result;
        }

        for(int i = 0; i <= nums.size(); i++) {
            long int current = (i == nums.size() ? (long)upper+1 : (long)nums[i]);

            if(current - previous >= 2) {
                result.push_back(getRange(previous+1,current-1));
            }

            previous = current;
        }
        return result;
    }
};

