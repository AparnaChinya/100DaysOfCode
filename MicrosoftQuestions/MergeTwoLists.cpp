/*
Merge Two Sorted Lists
  Go to Discuss
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

From <https://leetcode.com/explore/interview/card/microsoft/32/linked-list/175/>

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
        return MergeTwoListsHelper(l1,l2);
    }
    ListNode* MergeTwoListsHelper(ListNode* l1, ListNode* l2) {

        if(l1==NULL) {
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        //Dont forget to return the list after recursion
        if(l1->val <= l2->val) {
            l1->next = MergeTwoListsHelper(l1->next,l2);
            return l1;
        }
        else  if(l1->val >= l2->val) {
            l2->next = MergeTwoListsHelper(l1,l2->next);
            return l2;
        }

    }
};

