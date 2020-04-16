/**
 *一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。在每次预约服务之间要有休息时间，
因此她不能接受相邻的预约。给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。
 * @stime: 2020-03-24 08:35
 * @etime: 2020-03-24 
 */

#include <stdio.h>
//动态规划

//递归
int massage1(int* nums, int numsSize){

    int sum = 0;

    if(numsSize == 0)
        return 0;
    if(numsSize == 1)
        return nums[0];
    if(numsSize == 2)
        return nums[0] > nums[1] ? nums[0] : nums[1];
    if(numsSize == 3)
        return nums[0] + nums[2] > nums[1] ? nums[0] + nums[2]: nums[1];

    int one = nums[0] + massage(nums + 2, numsSize - 2);
    int two = nums[1] + massage(nums + 3, numsSize - 3);

    return one > two ? one : two;
}

int massage(int* nums, int numsSize){

    if(numsSize == 0) return 0;
    if(numsSize == 1) return nums[0];
    if(numsSize == 2) return nums[0] > nums[1] ? nums[0] : nums[1];

    int *dp = (int *)malloc(sizeof(int) * numsSize);

    int i = 0;
    for(i = 2; i < numsSize; i++){
        dp[i] = dp[i - 1] > dp[i - 2] + nums[i] ? dp[i - 1] : dp[i - 2] + nums[i];
    }

    
    return dp[i - 1];
}



//int arr[] = {226,174,214,16,218,48,153,131,128,17,157,142,88,43,37,157,43,221,191,68,206,23,225,82,54,118,111,46,80,49,245,63,25,194,72,80,143,55,209,18,55,122,65,66,177,101,63,201,172,130,103,225,142,46,86,185,62,138,212,192,125,77,223,188,99,228,90,25,193,211,84,239,119,234,85,83,123,120,131,203,219,10,82,35,120,180,249,106,37,169,225,54,103,55,166,124};
int arr[] = {226,18,48,153,131,128,17,157,142,88,43,37,157,43,221,191,68,206,23,225,82,54,118,111,46,80,49,245,63,25,194,72,80,143,55,209,123,120,131,203,219,10,82,35,120,180,249,106,37,169,225,54,103,55,166,124};
int main(){

    int ret = massage1(arr, sizeof(arr)/sizeof(int));
    printf("%d,%d\n", (int)sizeof(arr)/sizeof(int), ret);
    //printf("%d\n", (int)sizeof(arr)/sizeof(int));

    return 0;
}