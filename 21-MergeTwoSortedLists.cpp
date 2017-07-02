/*
Q:https://leetcode.com/problems/merge-two-sorted-lists/#/description

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

	ListNode Rest(INT_MIN);
      
	ListNode *Res = &Rest;

	while (l1&& l2)
	{
		if (l1->val < l2->val)
		{
			Res->next = (l1);
			l1 = l1->next;
           
					
		}
		else
		//	if (l1->val > l2->val)
			{
				Res->next = (l2);
				l2 = l2->next;
               
				
			}
		 Res = Res->next;
		
	}

	  Res->next = l1  ? l1: l2;
	
      return Rest.next;

}
};
