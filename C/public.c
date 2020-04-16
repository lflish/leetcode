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

//排序
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

//Fibonacci
//1、1、2、3、5、8、13、21
int func(int n)
{
    static int arr[100] = {0};

    if(n <= 2)
        arr[n] = 1;
    else if(arr[n] == 0)
        arr[n] = func(n - 1) + func(n - 2);
    return arr[n];
}

int main()
{

    printf("%d\n", func(45));
    return 0;
    int arr[] = {8,7,8,9};
    int size = sizeof(arr) / sizeof(int);
    qsort(arr,size, sizeof(int), cmp);
    printf("size = %d min = %d max = %d", size, arr[0], arr[size - 1]);
    while(size)
        printf("%d ",arr[size--]);
    printf("\n");
    
}

