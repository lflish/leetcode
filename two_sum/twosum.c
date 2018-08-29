#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct t{
        int total;
        int (*arr)[2];
};

int *twoSum(int *nums, int numsSize, int target)
{
        struct t hash[65536] = {{0}};

        int i = 0;
        for(i = 0; i < numsSize; i++){            
                do{ 
                        int value = target - nums[i];
                        int key = value & 0xffff;
                     

                        if(hash[key].total == 0)
                                break;

                        int (*arr)[2] = hash[key].arr;

                        int j = 0;           
                        for(; j < hash[key].total; j++){
                                if(arr[j][1] == value){
                                        int *brr = malloc(sizeof(int) * 2); 
                                        brr[0] = i;
                                        brr[1] = arr[j][0];
                                        return brr;
                                }   

                        }   
                }while(0);
            
                do{ 
                        int key = nums[i] & 0xffff;

                        if(hash[key].total == 0){
                                hash[key].arr = malloc(10 * sizeof(int) * 2);
                        }

                        int (*arr)[2] = hash[key].arr;

                        arr[hash[key].total][0] = i;
                        arr[hash[key].total++][1] = nums[i];
                }while(0);
        }

        return NULL;
}
int main()
{
	int arr[] = {22, 33, 2, 7, 11, 15};
	int *result = twoSum(arr, 6, 9);

	printf("%d %d\n", result[0], result[1]);

	return 0;
}
