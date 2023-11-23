
#include <stdlib.h>
#include <stdio.h>

#define MAXNUM 1000000000

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int majorityElement(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    return nums[numsSize/2];
}

int main()
{
    int arr1[] = {3,2,3};
    printf("{3,2,3} = %d\n", majorityElement(arr1, 3));

    int arr2[] = {2,2,1,1,1,2,2};
    printf("{2,2,1,1,1,1,2,2} = %d\n", majorityElement(arr2, sizeof(arr2)/4));
}