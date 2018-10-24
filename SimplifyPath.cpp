/*

71. Simplify Path
Given an absolute path for a file (Unix-style), simplify it. 
For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
path = "/a/../../b/../c//.//", => "/c"
path = "/a//b////c/d//././/..", => "/a/b/c"
In a UNIX-style file system, a period ('.') refers to the current directory, so it can be ignored in a simplified path. Additionally, a double period ("..") moves up a directory, so it cancels out whatever the last directory was. For more information, look here: https://en.wikipedia.org/wiki/Path_(computing)#Unix_style
Corner Cases:
	• Did you consider the case where path = "/../"?
In this case, you should return "/".
	• Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".

From <https://leetcode.com/problems/simplify-path/description/>


*/

class Solution {
public:
    string simplifyPath(string path) {
        stringstream s(path);
        string line = "";
        string result = "";
        vector<string> myVector;

        while(getline(s,line,'/')) {
            if(line == "." || line == "") {
                continue;
            }
            if(line == ".." && !myVector.empty()) {
                myVector.pop_back();
            } else if(line != "..") {
                myVector.push_back(line);
            }
        }

        for(auto i : myVector) {
            result += '/'+ i;
        }

        return result == "" ? "/" : result;
    }
};

