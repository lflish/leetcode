char * freqAlphabets(char * s){

    int i = 0, j = i + 2;
    int k = 0;
    char *buf = calloc(1, 1000);

    while(s[i] != '\0'){

        if(s[i + 1] == '\0'){
            buf[k++] = s[i] + 0x30;
            return buf;
        }else if(s[j] == '#'){
            buf[k++] = (s[i] - 0x30) * 10 + (s[i + 1] - 0x30) + 0x60;
            i += 3;
            j += 3;
            continue;
        }else if(s[j] == '\0'){
            buf[k++] = s[i] + 0x30;
            buf[k++] = s[i + 1] + 0x30;
            return buf;
        }

        buf[k++] = s[i] + 0x30;
        i++;j++;
    }
    return buf;
}
