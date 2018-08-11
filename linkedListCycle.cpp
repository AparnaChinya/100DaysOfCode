/*
Linked List Cycle

Given a linked list, determine if it has a cycle in it.
Follow up:
Can you solve it without using extra space?

From <https://leetcode.com/explore/learn/card/linked-list/214/two-pointer-technique/1212/>

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
    bool hasCycle(ListNode *head) {
        ListNode *turtle = head;
        ListNode* rabbit = head;

        while(rabbit != NULL && rabbit->next != NULL) {
            //Allowing the below two lines before checking takes care of test cases like [1,2]
            rabbit = rabbit->next->next;
            turtle = turtle->next;

            if(rabbit == turtle) {
                return true;
            }

        }
        return false;
    }
};

