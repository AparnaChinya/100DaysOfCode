/*
Reverse a singly linked list.

From <https://leetcode.com/problems/reverse-linked-list/tabs/description> 


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
        
        if(head==NULL || head->next==NULL) return head;
        
        ListNode *p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return p;
        
    }
};


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
    ListNode *helper(ListNode *head, ListNode *newHead) {
            if(head == NULL) {
                    return newHead;
            }
            ListNode *node = head->next;
            head->next = newHead;
            return helper(node,head);
    }

    ListNode* reverseList(ListNode* head) {
            return helper(head,NULL);
    }
};
