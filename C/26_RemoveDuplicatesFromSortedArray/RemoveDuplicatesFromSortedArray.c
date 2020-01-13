//
// Created by lflish on 2020/1/8.
//
int removeDuplicates(int* nums, int numsSize) {
    int h = 0, t = 1;

    if(numsSize == 0)
        return 0;

    while (t != numsSize){
        if(nums[h] == nums[t]){
            t++;
            continue;
        }
        nums[++h] = nums[t++];
    }
    return h + 1;
}
