/*
Binary Search Tree Iterator

Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
Calling next() will return the next smallest number in the BST.
Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
Credits:
Special thanks to @ts for adding this problem and creating all test cases.

From <https://leetcode.com/explore/interview/card/amazon/81/design/895/>
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    //Stack for all nodes in increasing order always
    stack<TreeNode *> myStack;

    BSTIterator(TreeNode *root) {
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        auto temp = myStack.top();
        myStack.pop();

        //Remember to call this here
        pushAll(temp->right);

        return temp->val;
    }

    void pushAll(TreeNode *root) {
        //Push all the leftmost nodes from the root the first time and after each next(), push the right nodes left nodes.
        while(root != NULL) {
            myStack.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

