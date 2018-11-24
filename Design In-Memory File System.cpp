/*
588. Design In-Memory File System
Design an in-memory file system to simulate the following functions:
ls: Given a path in string format. If it is a file path, return a list that only contains this file's name. If it is a directory path, return the list of file and directory names in this directory. Your output (file and directory names together) should in lexicographic order.
mkdir: Given a directory path that does not exist, you should make a new directory according to the path. If the middle directories in the path don't exist either, you should create them as well. This function has void return type.
addContentToFile: Given a file path and file content in string format. If the file doesn't exist, you need to create that file containing given content. If the file already exists, you need to append given content to original content. This function has void return type.
readContentFromFile: Given a file path, return its content in string format.
 
Example:
Input:
["FileSystem","ls","mkdir","addContentToFile","ls","readContentFromFile"]
[[],["/"],["/a/b/c"],["/a/b/c/d","hello"],["/"],["/a/b/c/d"]]
Output:
[null,[],null,null,["a"],"hello"]
Explanation:

 
Note:
	1. You can assume all file or directory paths are absolute paths which begin with / and do not end with / except that the path is just "/".
	2. You can assume that all operations will be passed valid parameters and users will not attempt to retrieve file content or list a directory or file that does not exist.
	3. You can assume that all directory names and file names only contain lower-case letters, and same names won't exist in the same directory.


From <https://leetcode.com/problems/design-in-memory-file-system/description/#_=_>
*/
class FileSystem {
public:
    struct TrieNode {
    public:
        bool isFile = false;
        string content = "";
        unordered_map<string,TrieNode*> children;
    };

    TrieNode *root;

    FileSystem() {
        root = new TrieNode();
    }

    vector<string> getPath(string &path) {
        vector<string> ans;
        stringstream ss(path);
        string line = "";
        while(getline(ss,line,'/')) {
            cout << line;
            if(line != "") ans.push_back(line);
        }
        return ans;
    }

    vector<string> ls(string path) {
        vector<string> strs = getPath(path);
        TrieNode *current = root;
        for(string &p : strs) {
            current = current->children[p];
        }
        if(current->isFile) {
            return {strs.back()};
        }

        vector<string> ans;
        for(auto &st : current->children) {
            ans.push_back(st.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }

    void mkdir(string path) {
        vector<string> strs = getPath(path);
        TrieNode *current = root;

        for(auto &p : strs) {
            if(current->children.count(p) == 0) {
                current->children[p] = new TrieNode();
            }
            current = current->children[p];
        }

    }

    void addContentToFile(string filePath, string content) {
        vector<string> strs = getPath(filePath);
        TrieNode *current = root;
        for(auto &p : strs) {
            if(current->children.count(p) == 0) {
                current->children[p] = new TrieNode();
            }
            current = current->children[p];
        }
        current->content += content;
        current->isFile = true;
    }

    string readContentFromFile(string filePath) {
        vector<string> strs = getPath(filePath);
        TrieNode *current = root;
        for(auto &p : strs) {
            current = current->children[p];
        }
        return current->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */