/*
Example 1:

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: 
The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
Example 2:

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: 
The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters

@stime 2020-03-17 22:12
一次过，但是性能不是百分百，内存超过100
*/

int countCharacters(char ** words, int wordsSize, char * chars){

    unsigned char base[128] = {0};
    unsigned char test[128] = {0};

    char *p = chars;
    int i = 0;
    int sum = 0;

    while(*p != '\0')
        base[(int)*p++] += 1; 


    for(; i < wordsSize; i++){

        memcpy(test + 0x61, base + 0x61, 30);
        int j = 0;

        for(j; words[i][j] != '\0';){
            if(test[words[i][j]] > 0){
                test[words[i][j]] -= 1;
                j++;
            }else{
                j = 0;
                break;
            }
        }
        sum += j;
    }

    return sum;
}