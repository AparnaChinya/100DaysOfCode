/*
92. Reverse Linked List II
Reverse a linked list from position m to n. Do it in one-pass.
Note: 1 ≤ m ≤ n ≤ length of list.
Example:
Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL

From <https://leetcode.com/problems/reverse-linked-list-ii/description/>
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode* previous = newHead;

        for(int i = 0; i < m - 1; i++) {
            previous = previous->next;
        }
        ListNode *current = previous->next;

        for(int j = 0; j < n- m; j++) {
            ListNode *move = current->next;
            current->next = move->next;
            move->next = previous->next;
            previous->next = move;
        }

        return newHead->next;
    }
};

