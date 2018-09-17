/*
232. Implement Queue using Stacks
DescriptionHintsSubmissionsDiscussSolution
Pick One

Implement the following operations of a queue using stacks.
	• push(x) -- Push element x to the back of queue.
	• pop() -- Removes the element from in front of queue.
	• peek() -- Get the front element.
	• empty() -- Return whether the queue is empty.
Example:
MyQueue queue = new MyQueue();
queue.push(1);
queue.push(2);
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false
Notes:
	• You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is emptyoperations are valid.
	• Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
	• You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

From <https://leetcode.com/problems/implement-queue-using-stacks/description/>
*/
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> myStack1;
    stack<int> myStack2;

    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        while(!myStack1.empty()) {
            myStack2.push(myStack1.top());
            myStack1.pop();
        }
        myStack2.push(x);
        while(!myStack2.empty()) {
            myStack1.push(myStack2.top());
            myStack2.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = myStack1.top();
        myStack1.pop();
        return x;

    }

    /** Get the front element. */
    int peek() {
        return myStack1.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        if(!myStack1.empty()) {
            return false;
        }
        return true;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

