#include <stdbool.h>

bool canJump(int* nums, int numsSize) {

    if (numsSize == 1){
        return true;
    }

    int stepNum = nums[0], i = 0;

    for(i = 1; stepNum > 0 && i < numsSize; i++){
        stepNum--;
        if(stepNum < nums[i]){
            stepNum = nums[i];
        }
    }

    if (i == numsSize){
        return true;
    }

    return false;
}