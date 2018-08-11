/*
Linked List Cycle II
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Note: Do not modify the linked list.
Follow up:
Can you solve it without using extra space?

From <https://leetcode.com/explore/learn/card/linked-list/214/two-pointer-technique/1214/>

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
    ListNode *detectCycle(ListNode *head) {
        ListNode *turtle = head;
        ListNode *rabbit = head;
        ListNode *first = head;

        while(rabbit != NULL && rabbit->next != NULL) {
            rabbit = rabbit->next->next;
            turtle = turtle->next;
            if(turtle == rabbit) {
                break;
            }
        }

        if(turtle != rabbit) {
            return NULL;
        }

        while(turtle != first) {
            turtle = turtle->next;
            first = first->next;
        }

        //Check textCases like [1] and return no cycle
        return first == NULL || first->next == NULL? NULL : first;
    }
};

