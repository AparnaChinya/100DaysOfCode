/*
658. Find K Closest Elements
Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.
Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
Note:
	1. The value k is positive and will always be smaller than the length of the sorted array.
	2. Length of the given array is positive and will not exceed 104
	3. Absolute value of elements in the array and x will not exceed 104


From <https://leetcode.com/problems/find-k-closest-elements/description/>

*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0;
        int high = arr.size()-1;
        int crossOver;
        int count = 0;
        vector<int> result;

        while(low < high) {
            int mid = (low + high) / 2;
            if(arr[mid] == x) {
                high = mid;
                break;
            } else if(arr[mid] > x) {
                high = mid-1;
            } else {
                low = mid + 1;
            }
        }

        low = high;
        high++;

        while(k > 0) {
            if(high >= arr.size() || (low >= 0 && (x - arr[low]) <= (arr[high] - x))){
                low--;
            } else {
                high++;
            }
            k--;
        }

        for(int i = low + 1; i < high; i++) {
            result.push_back(arr[i]);
        }

        return result;
    }
};

