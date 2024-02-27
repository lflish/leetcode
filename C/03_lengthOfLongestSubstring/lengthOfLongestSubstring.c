//给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//a,s,s,a,k,2,3,3,
int lengthOfLongestSubstring(char *s){

  unsigned char temp[128] = {0}, count = 0, max = 0;

  for(int i = 0; s && s[i] != '\0'; i++){
    if(temp[s[i]] == 0){
        temp[s[i]] = i + 1;
        count++;
    }else {
      i = temp[s[i]] - 1;
      memset(temp, 0, 128);
      count = 0;
    }

    if (count > max){
      max = count;
    }

  }

  return max;
}

int lengthOfLongestSubstringEx(char *s){

  char temp[128] = {}, count = 0, max = 0;
  int left = 0, right = 0;

  for(int i = 0; i < 128; i++){
    temp[i] = -1;
  }

   while( s && s[right] != '\0'){

    if(temp[s[right]] < 0){
        temp[s[right]] = right;
        count++;
        right++;
    }else {
      int head = temp[s[right]];
      for(int j = head; j >= left; j--){
          temp[j] = -1;
      }

      //head = 2
      //left = 0
      //right = 5

      // 1 2 3 4 5 6 3 8 9
      // 0 1 2 3 4 5 6 7 8
      // left = 3;
      left = head + 1;
      count = right - left + 1;
      temp[s[right]] = right;
    }

    if (count > max){
      max = count;
    }
  }

  return max;
}

int main(){
  printf("bbbb=%d\n", lengthOfLongestSubstring("bbbb"));
  printf("bbbb=%d\n", lengthOfLongestSubstringEx("bbbb"));
}