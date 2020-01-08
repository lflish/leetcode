//
// Created by lflish on 2020/1/8.
//
int maxSubArray(int* nums, int numsSize){
    int max = nums[0];
    int i_max = 0, i = 0;

    while(i < numsSize){

        i_max += nums[i++];
        if(i_max > max)
            max = i_max;

        if(i_max <= 0){
            i_max = 0;
        }
    }
    return max;
}
