//
// Created by lflish on 2019/12/31.
//

#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(int x){

    if(x < 0)
        return false;
    if(x >= 0 && x <= 9)
        return true;

    int tmp = x;
    int num = 0;
    int j = 0;

    while(tmp > 0) {

        if(++j  == 9){
            if(x % 10 > 2)
                return false;
        }

        num *= 10;
        num += tmp % 10;
        tmp = tmp / 10
    }

    if(x == num)
        return true;

    return false;
}

int arr[10] = {12345, 12321, 123321, 0, 10, -123};

int main()
{
    int i = 0;

    for (i = 0; i < 6; i++){
        printf("%d\t", arr[i]);
        printf("%s\n", isPalindrome(arr[i]) == true ? "true" : "false");

    }

    return 0;
}