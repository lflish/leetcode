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

    unsigned char buf[128] = {0};

    int sum = 0;
    char k = 0;

    while( (k = *s++) != '\0' ){
        if(buf[k] == 1){
            buf[k] = 0;
            sum += 2;
            continue;
        }
        buf[k] = 1;
    }

    //calc
    for(k = 0x41; k < 0x7a; k++){
        if(buf[k] == 1) 
            return sum + 1;
        if(k == 0x5a)
            k = 0x60;
    }

    return sum;
}

int main(){
    int r = longestPalindrome("abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa");
    printf("%d\n", r);
}