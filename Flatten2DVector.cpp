/*
251. Flatten 2D Vector
Implement an iterator to flatten a 2d vector.
Example:
Input: 2d vector =
[
  [1,2],
  [3],
  [4,5,6]
]
Output: [1,2,3,4,5,6]
Explanation: By calling next repeatedly until hasNext returns false,
             the order of elements returned by next should be: [1,2,3,4,5,6].
Follow up:
As an added challenge, try to code it using only iterators in C++ or iterators in Java.

From <https://leetcode.com/problems/flatten-2d-vector/description/>
*/

class Vector2D {
public:
    vector<vector<int>>::iterator i,j;
    int k = 0;

    Vector2D(vector<vector<int>>& vec2d) {
        i = vec2d.begin();
        j = vec2d.end();
    }

    int next() {
        hasNext();
        return (*i)[k++];
    }

    bool hasNext() {
        while(i != j && k == (*i).size()) {
            i++;
            k = 0;
        }
        return i != j;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

