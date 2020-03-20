/*
A rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) are the coordinates of its bottom-left corner, and (x2, y2) are the coordinates of its top-right corner.

Two rectangles overlap if the area of their intersection is positive.  To be clear, two rectangles that only touch at the corner or edges do not overlap.

Given two (axis-aligned) rectangles, return whether they overlap.

Example 1:

Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
Output: true
Example 2:

Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
Output: false
Notes:

Both rectangles rec1 and rec2 are lists of 4 integers.
All coordinates in rectangles will be between -10^9 and 10^9.

@stime 2020-03-18 21:50
*/
#include <stdbool.h>

bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){

    int *low = rec1, *higt = rec2;

    if(rec1[0] > rec2[0]){
        low = rec2;
        higt = rec1;
    }

    if(higt[0] >= low[2])
        return false;
    else if(higt[1] >= low[3])
        return false;
    if(higt[3] <= low[1])
        return false;

    return true;

}