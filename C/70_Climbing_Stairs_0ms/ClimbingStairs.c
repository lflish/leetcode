int climbStairs(int n){
    static int arr[46] = {0};
    
    if(n < 0 )
        return 0;
    if(n < 3)
        return n;

    if ( arr[n] == 0 ){
        arr[n] =  climbStairs(n - 2) + climbStairs(n - 1);
    }
    return arr[n];
}

/* 此题有暴力解法，应为整型长度限制，所以到46后就会溢出 */