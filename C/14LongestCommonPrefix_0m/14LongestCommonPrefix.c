//
// Created by lflish on 2020/1/1.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    char *index = *strs;
    int i = 0;

    for(; index[i] != '\0'; i++){
        int j = 0;
        for(; j < strsSize; j++){
            if(index[i] != strs[j][i]){
                goto end;
            }
        }
    }
    end:
    if(i != 0){
        char *buf = malloc(i + 100);
        strncpy(buf, index, i );
        buf[i] = '\0';

        return buf;
    }
    return "";
}

char *arr[3] = {"flower", "flow", "f2ight"};

int main()
{
    char *str = longestCommonPrefix(arr, 3);
    printf("%s\n", str);
    return 0;
}
