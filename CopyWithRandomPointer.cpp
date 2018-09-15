/* 138. Copy List with Random Pointer
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
Return a deep copy of the list.

From <https://leetcode.com/problems/copy-list-with-random-pointer/description/>

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) {
            return NULL;
        }

        RandomListNode *current = head;

        //Add duplicate nodes in the linkedlist
        while(current != NULL) {
            RandomListNode *temp = current->next;
            current->next = new RandomListNode(current->label);
            current->next->next = temp;
            current = current->next->next;
        }

        current = head;

        //Add the random pointers to the copied items in the list
        while(current != NULL) {
            current->next->random = current->random ? current->random->next : NULL;
            current = current->next->next;
        }

        RandomListNode *copy = head->next;
        RandomListNode *result = head->next;
        RandomListNode *original = head;

        //REMEMBER to remove the reference for original list followed by the copied list
        while(original != NULL) {
            original->next = original->next->next;
            copy->next = copy->next ? copy->next->next : copy->next;
            copy = copy->next;
            original = original->next;
        }
        return result;
    }
};

*/
