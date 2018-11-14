/*
428. Serialize and Deserialize N-ary Tree
DescriptionHintsSubmissionsDiscussSolution
Pick One

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
Design an algorithm to serialize and deserialize an N-ary tree. An N-ary tree is a rooted tree in which each node has no more than N children. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that an N-ary tree can be serialized to a string and this string can be deserialized to the original tree structure.
For example, you may serialize the following 3-ary tree
 

 
as [1 [3[5 6] 2 4]]. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
 
Note:
	1. N is in the range of [1, 1000]
	2. Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

From <https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/description/>

*/
/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
public:
    void serializeHelper(Node* root, string &result) {
        if(root == NULL) {
            return;
        }

        result += " " + to_string(root->val) + " " + to_string(root->children.size());

        for(auto i : root->children) {
            serializeHelper(i,result);
        }
    }

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string result = "";
        serializeHelper(root,result);
        return result;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        stringstream ss(data);
        return deserializeHelper(ss);
    }

    Node *deserializeHelper(stringstream &ss) {
        ss.peek();
        if(ss.eof()) {
            return NULL;
        }
        Node *root = new Node();
        int childrenSize;
        ss >> root->val >> childrenSize;

        for(int i = 0; i < childrenSize; i++) {
            root->children.push_back(deserializeHelper(ss));
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

