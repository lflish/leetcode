int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int longestConsecutive(int* nums, int numsSize) {

    qsort(nums, numsSize, sizeof(int), cmp);
    
    if (numsSize == 1)
        return 1;

    int sum = 0, count = 1;

    for(int i = 0; i < numsSize - 1; i++){

        if(nums[i] == nums[i+1]){
            ;
        }else if(nums[i] + 1 == (nums[i+1])){
            //count = count == 0 ? 2 : count + 1;
            count += 1;
        }else{
            count = 1;
        }
        
        if (count > sum){
            sum = count;
        }
    }

    return sum;
}