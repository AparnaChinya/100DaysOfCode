/*

The API: int read4(char *buf) reads 4 characters at a time from a file.
The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
Example 1:
Input: buf = "abc", n = 4
Output: "abc"
Explanation: The actual number of characters read is 3, which is "abc".
Example 2:
Input: buf = "abcde", n = 5
Output: "abcde"
Note:
The read function will only be called once for each test case.

From <https://leetcode.com/explore/interview/card/google/59/array-and-strings/396>
*/

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int i = 0;

        while(n > 0) {
            i += min(read4(buf),n);
            buf += 4;
            n-= 4;
        }
        return i;
    }
};

