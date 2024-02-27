#include <stdio.h>
#include <stdlib.h>

// 2, 3, 4 ,2 ,3 ,5

// 4, 3, 2 ,2 ,3 ,5
//i=0

// 3, 3, 2 ,2 ,4 ,5
//i=0

// 2, 3, 2, 3 ,4 ,5
//i=0

// 2, 3, 2, 3 ,4 ,5
//i=1

int* findDuplicates(int* nums, int numsSize, int* returnSize){

  int i = 0;

  int *result = malloc(numsSize/2);
  if (result == NULL){
    return NULL;
  }

  for(i =0; i < numsSize; i++ ){
    nums[i] = nums[i] - 1;
  }

  *returnSize = 0;

  if(numsSize <= 1 || nums == NULL || returnSize == NULL){
    return NULL;
  }
  
  for(i =0; i < numsSize; i++ ){
    int m = nums[i];

    if (i == m || m == -1){
      continue;
    }else if(m == nums[m]){

      result[*returnSize] = m + 1;
      (*returnSize)++;

      nums[i] = -1;
      nums[m] = -1;

    }else if(i != m){
      int tmp = nums[m];
      nums[m] = nums[i];
      nums[i] = tmp;
      i--;
    }
  }

  return result;
}

int main(){
  // 2, 3, 4 ,2 ,3 ,5
  //int arr[] = {2, 3, 4, 2, 3 ,5};
  int arr[] = {4,3,2,7,8,2,3,1};
  int size;

  int *list = findDuplicates(arr, sizeof(arr)/sizeof(int), &size);

  for(int i = 0; i < size; i++){
    printf("%d,", list[i]);
  }

  printf("\n");
  return 0;
}