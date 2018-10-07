/* 223. Rectangle Area
DescriptionHintsSubmissionsDiscussSolution
Pick One

Find the total area covered by two rectilinear rectangles in a 2D plane.
Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

From <https://leetcode.com/problems/rectangle-area/description/>
*/

class Solution {
public:
    bool OverLap(int a, int b, int c, int d, int e, int f, int g, int h) {
        if(c < e || g < a) {
            return false;
        }
        if(d < f || h < b) {
            return false;
        }

        return true;
    }


    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = abs(A-C) * abs(B-D);
        int area2 = abs(E-G) * abs(F-H);
        int areaI = 0;
        //Check if they overlap
        if(OverLap(A,B,C,D,E,F,G,H))
            areaI = (min(C,G)-max(A,E)) * (min(D,H) - max(B,F));

        return area1 + area2 - areaI;
    }
};

