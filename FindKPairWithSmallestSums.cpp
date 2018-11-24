/*
373. Find K Pairs with Smallest Sums
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
Define a pair (u,v) which consists of one element from the first array and one element from the second array.
Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
Example 1:
Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence:
             [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:
Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [1,1],[1,1]
Explanation: The first 2 pairs are returned from the sequence:
             [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:
Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [1,3],[2,3]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]

From <https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/>
*/

class Solution {
public:
    struct compare {
        bool operator() (pair<int,int> &a, pair<int,int> &b) {
            return a.first + a.second < b.first + b.second;
        }
    };

    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> myQueue;
        vector<pair<int,int>> result;

        for(auto n1 : nums1) {
            for(auto n2 : nums2) {
                myQueue.push(make_pair(n1,n2));
                if(myQueue.size() > k) {
                    myQueue.pop();
                }
            }
        }

        while(!myQueue.empty()) {
            result.push_back(myQueue.top());
            myQueue.pop();
        }
        return result;
    }
};

