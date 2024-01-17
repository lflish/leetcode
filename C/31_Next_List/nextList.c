//不要用快排，这个是有窍门的，最后颠倒顺序即可
void sort(int *nums, int size){
    for(int i = 0, j = size - 1; i < j; i++, j--){
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
    }
}

void nextPermutation(int* nums, int numsSize) {

    for(int i = numsSize - 1; i > 0; i--){
        if (nums[i] > nums[i - 1]){

            int min = i;
            for(int j = i; j < numsSize; j++){
                if(nums[j] <= nums[min] && nums[j] > nums[i - 1]){
                    min = j;
                }
            }

            int tmp = nums[min];
            nums[min] = nums[i-1];
            nums[i - 1] = tmp;

            sort(nums + i, numsSize - i);
            return;
        }
    }
    
    sort(nums, numsSize);
}