/*
Add Two Numbers
  Go to Discuss
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

From <https://leetcode.com/explore/interview/card/microsoft/32/linked-list/170/>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) {
            return l2;
        }
        if(l2 == NULL) {
            return l1;
        }
        ListNode* result = new ListNode(0);
        ListNode *solution = result;
        int carry = 0;
        int a;
        int b;
        int temp;

        while(l1 != NULL || l2 != NULL) {
            a = l1 == NULL ? 0 : l1->val;
            b = l2 == NULL ? 0 : l2->val;
            int temp = a + b + carry;
            carry = temp/10;
            temp = temp % 10;
            result->next = new ListNode(temp);
            result = result->next;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        if(carry > 0) {
            result->next = new ListNode(carry);
            result = result->next;
        }

        return solution->next;
    }
};

