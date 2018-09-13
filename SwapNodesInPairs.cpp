/*
24. Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return its head.
Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.
Note:
	• Your algorithm should use only constant extra space.
	• You may not modify the values in the list's nodes, only nodes itself may be changed.

From <https://leetcode.com/problems/swap-nodes-in-pairs/description/>
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *previous = dummy;

        ListNode *current = head;

        while(current != NULL && current->next != NULL) {
            ListNode* temp = current->next->next;
            previous->next = current->next;
            current->next->next = current;
            current->next = temp;
            previous = current;
            current = temp;

        }


        return dummy->next;
    }
};

