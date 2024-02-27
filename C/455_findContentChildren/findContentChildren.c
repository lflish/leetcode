/*
   qsort 

   g[i] <= s[j] ++

   g[i] > s[j] j++
*/

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    int count = 0;

    if (!g || !s){
        return 0;
    }

    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);

    int i = 0, j = 0;

    while( i < gSize && j < sSize){
        if (g[i] <= s[j]){
            i++;
            j++;
            count++;
        }else{
            j++;
        }
    }

    return count;
}