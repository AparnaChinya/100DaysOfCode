/*
Add Two Numbers II
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
Example:
Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

From <https://leetcode.com/explore/interview/card/microsoft/32/linked-list/205/>
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
        //Code is long but it is simple!

        //Two stacks, push each node to stacks
        stack<int> stackOne;
        stack<int> stackTwo;
        int carry = 0;
        ListNode *result = new ListNode(0);
        ListNode *solution = result;

        while(l1!=NULL){
            stackOne.push(l1->val);
            l1 = l1->next;
        }
        while(l2!=NULL){
            stackTwo.push(l2->val);
            l2 = l2->next;
        }

        //add digits and add to end of the list
        while(!stackOne.empty() || !stackTwo.empty()) {
            int a = (stackOne.empty()) == true ? 0 :  stackOne.top();
            int b = (stackTwo.empty()) == true ? 0 :  stackTwo.top();

            int sum = a + b + carry;
            carry = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            cout << sum << " ";
            result->next = node;
            result = result->next;

            if(!stackOne.empty()) {
                stackOne.pop();
            }
            if(!stackTwo.empty()) {
                stackTwo.pop();
            }
        }
        //Dont forget to check for the carry over
        if(carry > 0){
            ListNode *carryNode = new ListNode(carry);
            result->next = carryNode;
            result = result->next;
        }

        ListNode *reverseList = solution->next;
        ListNode *previous = NULL;

        //reverse the list
        while(reverseList != NULL) {
            ListNode *temp = reverseList->next;
            reverseList->next = previous;
            previous = reverseList;
            reverseList = temp;
        }

        return previous;
        //O(m+n) Space O(m+n) time
    }
};

