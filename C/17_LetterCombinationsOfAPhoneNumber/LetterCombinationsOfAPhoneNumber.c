
// Created by lflish on 2020/10/20
// 这道题很有代表性,而且相对简单，直接使用栈数据完美解决
//


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>

char ** letterCombinations(char * digits, int* returnSize){
    if(digits == NULL || digits[0] == '\0'){
        *returnSize = 0;
        return NULL;
    }

    int i,j,k,l;
    int arr_tail = 0;
    int len = strlen(digits);
    int arr_len = pow(4, len);

    static char *map[12] = {NULL, 
        NULL, 
        "abc", 
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
        NULL};

    char **arr = malloc((arr_len + 1) * sizeof(char *));
    memset(arr, 0, sizeof(arr_len + 1) *sizeof(char *));


    for(i = 0; digits[i] != '\0'; i++){

        char c = digits[i];
        int total = 0;

        if(c == '7' || c == '9')
            total = 4;
        else if(c > '9' || c <= '1'){
            *returnSize = 0;
            return NULL;
        }
        else 
            total = 3;

        int j = 0;

        //init 
        if(arr_tail == 0){
            for(j = 0; j < total; j++){
                arr[j] = malloc(len + 1);
                memset(arr[j], 0, len + 1);
                arr[j][i] = map[c - 0x30][j];
            }
            arr_tail = total;
            continue;
        }

        //copy
        for(j = 0; j < total - 1; j++){

            int k = 0;

            for(k = 0; k < arr_tail; k++){

                int pos = (j + 1) *arr_tail + k;

                arr[pos] = malloc(len + 1);
                memset(arr[pos], 0, len + 1);
                memcpy(arr[pos], arr[k], len + 1);
            }
        }

        // set value
        for(j = 0; j < total; j++){

            int k = 0;
            for(k = 0; k < arr_tail; k++){
                int pos = j * arr_tail + k;
                arr[pos][i] = map[c - 0x30][j];
            }
        }
        arr_tail *= total;
    }

    *returnSize = arr_tail;

    return arr;
}