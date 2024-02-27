void reverseString(char* s, int sSize) {
    int i = 0, j = sSize - 1;

    for(; i < j; i++, j--){
        int tmp  = s[i];
        s[i] =  s[j];
        s[j] = tmp;
    }
}