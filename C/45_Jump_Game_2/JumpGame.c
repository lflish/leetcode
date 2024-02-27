int jump(int* nums, int numsSize) {

    int i = 0, count = 1;
    int step = nums[i];

    if (numsSize == 1)
        return 0;

    while(i + step < numsSize - 1){
       int max = 0, max_i = 0;

       for(int j = 1; j <= step; j++) {
           if (nums[i + j] + j > max){
               max = nums[j + i] + j;
               max_i = j + i;
           }
       }

       i = max_i;
       step = nums[max_i];
       count++;
    }

    return count;
}