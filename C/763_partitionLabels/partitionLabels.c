/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// double arr travel
// 2.10
#include <stdlib.h>
#include <stdio.h>

int *partitionLabels(char *s, int *returnSize)
{
    int map[128] = {0};
    char *p = s;
    int count = 0, retMax = 0;

    while (*p != '\0')
    {
        map[*p] = p - s;
        p++;
        retMax++;
    }

    int *retArray = malloc(sizeof(int) * retMax);

    for (int i = 0; s[i] != '\0'; i++, count++)
    {
        if (map[s[i]] == i)
        {
            retArray[count] = map[s[i]] - i + 1;
            continue;
        }

        int max_i = map[s[i]];
        for (int j = i; j < max_i; j++)
        {
            if (map[s[j]] > max_i)
            {
                max_i = map[s[j]];
            }
        }

        retArray[count] = max_i - i + 1;
        i = max_i;
    }

    *returnSize = count;
    return retArray;
}

int main()
{
    char *s = "ababcbacadefegdehijhklij";
    int p = 0;
    int *arr = partitionLabels(s, &p);

    for (int i = 0; i < p; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");

    return 0;
}
