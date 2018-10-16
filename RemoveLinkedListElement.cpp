/*203. Remove Linked List Elements
Remove all elements from a linked list of integers that have value val.
Example:
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5

From <https://leetcode.com/problems/remove-linked-list-elements/description/>

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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) {
            return NULL;
        }
        head->next = removeElements(head->next,val);
        return head->val == val ? head->next : head;
    }
};

g