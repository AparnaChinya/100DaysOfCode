/*
149. Max Points on a Line
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
Example 1:
Input: [[1,1],[2,2],[3,3]]
Output: 3
Explanation:
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4
Example 2:
Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
Explanation:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6
From <https://leetcode.com/problems/max-points-on-a-line/description/>
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size() < 2) {
            return points.size();
        }
        int localmax ;
        int vertical;
        int duplicates;
        int result = 0;

        for(int i = 0; i < points.size(); i++) {
            map<pair<int,int>,int> myMap;
            localmax = vertical = duplicates = 0;

            for(int j = i + 1; j < points.size(); j++) {
                //Check for duplicaes
                if(points[i].x == points[j].x && points[i].y == points[j].y) {
                    duplicates++;
                    continue;
                }
                //check for vertical point, if its not there then calculate slope
                if(points[i].x == points[j].x) {
                    vertical++;
                } else {
                    int slopeX = points[i].x - points[j].x;
                    int slopeY = points[i].y - points[j].y;

                    int g = gcd(slopeX,slopeY);

                    slopeX /= g; slopeY /= g;
                    //put slope in map
                    myMap[make_pair(slopeX,slopeY)]++;

                    //calculate localmax
                    localmax = max(localmax,myMap[make_pair(slopeX,slopeY)]);
                }
                //Caculate max of map of slope and vertical
                localmax = max(localmax,vertical);
            }
            //Calculate max of result and localmax + duplicates + 1;
            result = max(result,localmax + duplicates + 1);
        }

        return result;
    }

    int gcd(int a, int b) {
        if(b == 0) {
            return a;
        }
        else return gcd(b,a%b);
    }
};

