/*
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

@stime 2020-03-19 18:02
*/

int longestPalindrome(char * s){
    unsigned int buf[128] = {0};

    int i = 0;
    int sum = 0;

    //sort
    while( (i = *s++) != '\0' )
        buf[i] += 1;

    //calc
    int flag = 0;
    while(i < 128){
        if(buf[i] % 2 == 0) 
            sum += buf[i];
        else if(buf[i] - 1 > 0){
            flag = 1;
            sum += buf[i] - 1;
        }
        else if(flag == 0)
            flag = 1;

        i++;
    }
    return flag + sum;
}

int main(){
    int r = longestPalindrome("abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa");
    printf("%d\n", r);
}