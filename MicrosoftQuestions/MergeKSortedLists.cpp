/* Merge k Sorted Lists
  Go to Discuss
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
Example:
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6

From <https://leetcode.com/explore/interview/card/microsoft/32/linked-list/209/>
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size() == 0) {
            return NULL;
        }
        while(lists.size() != 1) {
            lists.push_back(mergeListHelper(lists[0],lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists[0];
    }

    ListNode *mergeListHelper(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) {
            return l2;
        }
        if(l2 == NULL) {
            return l1;
        }
        if(l1->val <= l2->val) {
            l1->next = mergeListHelper(l1->next,l2);
            return l1;
        }
        if(l2->val <= l1->val) {
            l2->next = mergeListHelper(l1, l2->next);
            return l2;
        }
    }
};

