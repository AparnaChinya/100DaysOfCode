/*
 Reverse Linked List

Reverse a singly linked list.
Example:
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:
A linked list can be reversed either iteratively or recursively. Could you implement both?

From <https://leetcode.com/explore/interview/card/microsoft/32/linked-list/169/>

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
    ListNode* reverseList(ListNode* head) {
        ListNode *previous = NULL;

        while(head != NULL) {
            ListNode *temp = head->next;
            head->next = previous;
            previous = head;
            head = temp;
        }
        return previous;
    }
};

