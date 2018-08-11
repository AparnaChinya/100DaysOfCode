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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *current = head;
        ListNode *start = head;

        while(current!= NULL) {
            current = current->next;
            //Only if we have reached a position where n is less than 0
            if(n < 0) {
                start = start->next;
            }
            n--;
        }

        if(n == 0) {
            head =  head->next;
        } else {
            start->next =start->next->next;
        }

        return head;
    }
};