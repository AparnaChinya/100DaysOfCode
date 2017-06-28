/*
Q: https://leetcode.com/problems/add-two-numbers/#/description

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
		ListNode *dummyHead = new ListNode(0);

		ListNode *p = l1, *q = l2, *curr = dummyHead;

		int carry = 0;

		while (p != NULL || q != NULL)
		{
			int a = (p != NULL) ? p->val : 0;
			int b = (q != NULL) ? q->val : 0;

			int Sum = a + b + carry;
			carry = Sum / 10;
			int temp = Sum % 10;
			curr->next = new ListNode(temp);
			curr = curr->next;

			if (p != NULL) p = p->next;
			if (q != NULL) q = q->next;
		}
		if (carry>0)
		{
			ListNode *l = new ListNode(carry);
			curr->next = l;
		}

		return dummyHead->next;
	}
};