//
// Created by lflish on 2020/1/8.
// 这道题很有代表性,而且相对简单，直接使用栈数据完美解决
//

bool isValid(char * s){

    if(s[0]!= 0 && s[1] == 0)
        return false;

    int len = strlen(s);
    char *stack = malloc(len + 3);

    int i = 0, j = 0;
    for(i ; s[i] != '\0'; i++){

        if (s[i] == '('  ||
            s[i] == '{' ||
            s[i] == '['){
            stack[++j] = s[i];
            continue;
        }else if(s[i] == ')' && stack[j] == '('){
            j--;
            continue;
        }else if(s[i] == '}' && stack[j] == '{'){
            j--;
            continue;
        }else if(s[i] == ']' && stack[j] == '['){
            j--;
            continue;
        }

        return false;
    }
    if(j == 0)
        return true;
    return false;
}