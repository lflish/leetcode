/*
    Input: prices = [7,1,5,3,6,4]
                      -6 4 -2 3 - 2
    Output: 5
*/

int maxProfit(int* prices, int pricesSize) {
    int max = 0, sum = 0;

    for(int i = 1; i < pricesSize; i++){
        sum += prices[i] - prices[i - 1];

        if (sum <= 0){
            sum = 0;
        }else if(sum > max){
            max = sum;
        }
    }

    return max;    
}