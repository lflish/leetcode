/*
You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. You need to determine whether it is possible to measure exactly z litres using these two jugs.

If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.

Operations allowed:

Fill any of the jugs completely with water.
Empty any of the jugs.
Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.
Example 1: (From the famous "Die Hard" example)

Input: x = 3, y = 5, z = 4
Output: True
Example 2:

Input: x = 2, y = 6, z = 5
Output: False
@stime: 2020-03-21 14:49
*/

#include <stdbool.h>

// 最大公约数
int GreatestCommonDivisor(int a, int b)
{
    if (a == 0 || b == 0)
        return b + a;

    while(a != b){
        if(a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

bool canMeasureWater(int x, int y, int z){

    if( x + y < z)
        return false;

    int n = GreatestCommonDivisor(x, y);

    if(z % n == 0)
        return true;

    return false;
}