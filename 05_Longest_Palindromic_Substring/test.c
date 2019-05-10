#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* longestPalindrome(char* s) {

        int max_i, max_j;
        int tmp_i, tmp_j;
        int max = 0;
        int i;
    
        int len = strlen(s);    

        for(i = 0; i < len - 1; i++){
                if(s[i] == s[i + 1]){
                        tmp_i = i - 1;
                        tmp_j = i + 2;

                        int tmp = 2;

                        for(; tmp_i > 0 && tmp_j < len - 1; tmp_i--, tmp_j++){
                                if(s[tmp_i] != s[tmp_j])
                                        break;
                                tmp += 2;
                        }   

                        if(tmp > max){
                                max_i = tmp_i + 1;
                                max_j = tmp_j - 1;
                                max = tmp;
				printf("max_i = %d max = %d\n" ,max_i, max);
                        }   
                }   

                if(s[i] == s[i + 2]){
                        tmp_i = i - 1;
                        tmp_j = i + 3;

                        int tmp = 3;

                        for(; tmp_i > 0 && tmp_j < len - 1; tmp_i--, tmp_j++){
                                if(s[tmp_i] != s[tmp_j])
                                        break;
                                tmp += 2;
                        }   

                        if(tmp > max){
                                max = tmp;
                                max_i = tmp_i + 1;
                                max_j = tmp_j - 1;
				printf("max_i = %d, max = %d\n" ,max_i, max);
                        }   
                }   
        }   
        printf("%d %d %d\n", max_i, max_j, max);
    
        char *p = malloc(1000);
        memset(p, 0, 1000);
    
        memcpy(p, s + max_i, max );
    
        return p;
}

int main()
{
	char s[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

	//char s[] = "cbbd";

	int n = strlen(s);

	printf(" n = %d, result = [%s]\n", n, longestPalindrome(s));

	return 0;
}
