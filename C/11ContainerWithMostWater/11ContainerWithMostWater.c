//
// Created by lflish on 2020/1/5.
//

int maxArea(int* height, int heightSize){
    int max = 0;
    int i = 0, j = 0;

    while(i < heightSize){

        for(j = i + 1; j < heightSize; j++){
           int value = (j - i) * ( height[i] > height[j] ? height[j] : height[i]);

            if( value > max){
                max = value;
            }
        }
        i++;
    }
    return max;
}