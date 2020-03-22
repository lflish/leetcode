/*

Given an array of integers A, a move consists of choosing any A[i], and incrementing it by 1.

Return the least number of moves to macure every value in A unique.

 

Example 1:

Input: [1,2,2]
Output: 1
Explanation:  After 1 move, the array could be [1, 2, 3].
Example 2:

Input: [3,2,1,2,1,7]
Output: 6
Explanation:  After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
It can be shown with 5 or less moves that it is impossible for the array to have all unique values.
 

Note:

0 <= A.length <= 40000
0 <= A[i] < 40000

@stime:2020-03-21:14:08
*/

#include <stdio.h>

int minIncrementForUnique(int* A, int ASize){

    int i = 0;
    int sum = 0, cur = 0;

    unsigned short int hash[40500] = {0};

    // 整理
    while( i < ASize )
        hash[A[i++]] += 1;

    //遍历1
    for(i = 0; i < 40000; i++){

        cur = (i >= cur ? i + 1 : cur);

        if (hash[i] > 1){
            int num = hash[i] - 1;

            while(num){
                if( hash[cur] == 0){
                    sum += cur - i;
                    num--; cur++;
                }
                else
                    cur++;
            }
        }
    }
    return sum;
}

int main()
{
    int arr[] = {3,2,1,2,1,7};
    int r = minIncrementForUnique(arr, sizeof(arr) / sizeof(int));
    printf("%d\n", r);
}

