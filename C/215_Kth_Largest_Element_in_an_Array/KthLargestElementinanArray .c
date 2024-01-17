//

int findKthLargest(int* nums, int numsSize, int k) {
    int *map = malloc(sizeof(int) * 30000);
    memset(map, 0, sizeof(int) * 30000);

    for(int i = 0; i < numsSize; i++){
        map[nums[i] + 10000]++;
    }

    for(int i = 20000; i >= 0; i--){
        if(map[i] != 0){
            k -= map[i];
        }

        if(k <= 0){
            return i - 10000;
        }
        
    }

    free(map);
    return 0;
}