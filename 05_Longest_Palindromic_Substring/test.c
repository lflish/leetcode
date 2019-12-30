#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char * longestPalindrome(char * s){
    int max_i = 0;
    int max_j = 0;
    int max_len = 0;
    char *buf = malloc(1024);

    memset(buf, 0, 1024);
    int i = 0;

    for(i; s[i] != '\0'; i++){
        /* 1 */
        if(s[i + 1 ] == '\0')
            break;

        if( s[i] == s[i + 1] ){
            int t_i = i;
            int t_j = i + 1;
            for(; t_i >= 0 && s[t_j] != '\0'; t_i--, t_j++){

                if(s[t_i] != s[t_j])
                    break;

                int len = t_j - t_i;
                if(len > max_len){
                    max_i = t_i;
                    max_j = t_j;
                    max_len = len;
                }
            }
        }
        if(s[i + 2 ] == '\0')
            break;
        /* 2 */
        if( s[ i ] == s[i + 2] ){
            int t_i = i;
            int t_j = i + 2;
            for(; t_i >= 0 && s[t_j] != '\0'; t_i--, t_j++){

                if(s[t_i] != s[t_j])
                    break;

                int len = t_j - t_i;
                if(len > max_len){
                    max_i = t_i;
                    max_j = t_j;
                    max_len = len;
                }
            }
        }
    }
    memcpy(buf, &s[max_i], max_len + 1);

    return buf;
}
int main()
{
	char s[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

	//char s[] = "cbbd";

	int n = strlen(s);

	printf(" n = %d, result = [%s]\n", n, longestPalindrome(s));

	return 0;
}
