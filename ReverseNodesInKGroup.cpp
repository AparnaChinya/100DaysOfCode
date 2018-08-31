/* Reverse Nodes in k-Group
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
Example:
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
Note:
	• Only constant extra memory is allowed.
	• You may not alter the values in the list's nodes, only nodes itself may be changed.

From <https://leetcode.com/problems/reverse-nodes-in-k-group/description/>

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
    ListNode *reverse(ListNode *first, ListNode* last) {
        //reverse the linked list here
        ListNode *previous = last;

        while(first != last) {
            ListNode* temp = first->next;
            first->next = previous;
            previous = first;
            first = temp;
        }

        return previous;
    }
    //Recursion is the easiest approach
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *node = head;

        //If there are less than k elements then dont reverse
        for(int i = 0; i < k; i++) {
            if(node != NULL) {
                node = node->next;
            } else {
                return head;
            }
        }
        //Get the new head by reversing from start to end
        auto newHead = reverse(head,node);

        //the head next should be the reverse of the list
        head->next = reverseKGroup(node,k);

        //return the newhead
        return newHead;
    }
};


