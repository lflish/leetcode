/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int* genRows(int numRows, int* last) {

    int *arr = malloc(sizeof(int) * numRows);

    if(numRows == 1){
       arr[0] = 1;
       return arr;
    }else if (numRows == 2){
       arr[0] = 1;
       arr[1] = 1;
        return arr;
    }

    arr[0] = 1;

    for(int i = 1; i < numRows - 1; i++){
        arr[i] = last[i - 1] + last[i];
    }

    arr[numRows - 1] = 1;
    return arr;
}

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
   
   *returnSize = numRows;

   int **arr = (int **)malloc(sizeof(int*) * numRows);
   int *rowSize = malloc(sizeof(int) * numRows);
   *returnColumnSizes = rowSize;

   memset(arr, 0, sizeof(int*) * numRows);
   memset(rowSize, 0, sizeof(int) * numRows);
   
   for(int i = 0; i < numRows; i++){
       rowSize[i] = i + 1;
       arr[i] = genRows(rowSize[i], i > 1 ? arr[i - 1]: NULL);
   }

   return arr;
}