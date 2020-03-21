#include <stdio.h>
#include <stdlib.h>



//二分查找
int TwoFind(int *arrs, int size, int target)
{
    int left = 0, right = size - 1;
    int mid = 0;

	while (left < right ){

        mid= (left + right) / 2;

		if (target == arrs[mid])
            return mid;
        else if (target > arrs[mid])
            left = right + 1;
        else if (target < arrs[mid])
            right = mid - 1;
    }
    return 0;
}

// 最大公约数
int GreatestCommonDivisor(int a, int b)
{
    if (a == 0 || b == 0)
        return b + a;

    while(a != b){
        if(a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}


