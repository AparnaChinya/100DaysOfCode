/*
Intersection of Two Linked Lists

Write a program to find the node at which the intersection of two singly linked lists begins.
For example, the following two linked lists:
A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
begin to intersect at node c1.
Notes:
	• If the two linked lists have no intersection at all, return null.
	• The linked lists must retain their original structure after the function returns.
	• You may assume there are no cycles anywhere in the entire linked structure.
	• Your code should preferably run in O(n) time and use only O(1) memory.

From <https://leetcode.com/explore/learn/card/linked-list/214/two-pointer-technique/1215/>

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if(headA == NULL || headB == NULL) {
            return NULL;
        }

        ListNode *headAPointer = headA;
        ListNode *headBPointer = headB;

        while(headAPointer != NULL && headBPointer != NULL && headAPointer != headBPointer) {

            headAPointer = headAPointer->next;
            headBPointer = headBPointer->next;

            if(headAPointer == headBPointer) {
                return headAPointer;
            }

            //Remember to point end of the list to the other list first item
            if(headAPointer == NULL) {
                headAPointer = headB;
            }

            if(headBPointer == NULL) {
                headBPointer = headA;
            }
        }
        return headBPointer;
    }
};
