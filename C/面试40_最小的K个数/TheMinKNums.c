/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 
 * @stime: 2020-03-20: 22:13
 * @etime: 2020-03-20: 22:25
 */

int cmp(void *a, void *b)
{
     return *(int *)a  - *(int *)b;
}
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    
    // n * logn
    qsort(arr, arrSize, sizeof(int), cmp);

    int *ret = (int *) malloc( sizeof(int) * k );
    
    *returnSize = k;
    memcpy(ret, arr, k * (sizeof(int)));

    return ret;
}