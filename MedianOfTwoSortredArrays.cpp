/*4. Median of Two Sorted Arrays
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.
Example 1:
nums1 = [1, 3]
nums2 = [2]
The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5

From <https://leetcode.com/problems/median-of-two-sorted-arrays/description/>
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int lengthOfX = nums1.size();
        int lengthOfY = nums2.size();

        if(lengthOfX > lengthOfY) {
            return findMedianSortedArrays(nums2,nums1);
        }

        int start = 0; int end = lengthOfX;
        // End is length of X
        //Divide into partitions of equal length and Binary Search
        //Time Complexity : O(log(min(x,y)));
        while(start <= end) {
            int PartitionOfX = (start + end) / 2;
            int PartitionOfY = (lengthOfX + lengthOfY + 1) / 2 - PartitionOfX;

            int maxLeftOfX = PartitionOfX == 0 ? INT_MIN : nums1[PartitionOfX - 1] ;
            int maxLeftOfY = PartitionOfY == 0 ? INT_MIN : nums2[PartitionOfY - 1];

            int minRightOfX = PartitionOfX >= lengthOfX ? INT_MAX : nums1[PartitionOfX] ;
            int minRightOfY = PartitionOfY >= lengthOfY ? INT_MAX : nums2[PartitionOfY];

            if(maxLeftOfX <= minRightOfY && maxLeftOfY <= minRightOfX) {
                if((lengthOfX + lengthOfY) % 2 == 0) {
                    cout << max(maxLeftOfX,maxLeftOfY) + min(minRightOfX,minRightOfY) << endl;
                    return (double)(max(maxLeftOfX,maxLeftOfY) + min(minRightOfX,minRightOfY))/2;
                }
                else
                    return max(maxLeftOfX,maxLeftOfY);

            }
            else if(maxLeftOfX > minRightOfY) {
                // cout<< "end" << PartitionOfX - 1 << endl;
                end = PartitionOfX - 1;
            }
            else {
                // cout<< "start" << PartitionOfX + 1 << endl;
                start = PartitionOfX + 1;
            }

        }
    }
};

