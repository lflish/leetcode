//first set count + 1
//map += 1


void dfs(char** grid, int i, int j, int size, int colSize) {
   //youxia 
    grid[i][j] = 0;

    //上
    if (i - 1 >= 0 && grid[i - 1][j] == '1'){
        dfs(grid, i - 1, j, size, colSize);
    }

    //下
    if (i + 1 < size && grid[i + 1][j] == '1'){
        dfs(grid, i + 1, j, size, colSize);
    }

    //左
    if (j - 1 >= 0 && grid[i][j - 1] == '1'){
        dfs(grid, i, j - 1, size, colSize);
    }

    //右
    if (j + 1 < colSize && grid[i][j + 1] == '1'){
        dfs(grid, i, j + 1, size, colSize);
    }

    return;
}

int numIslands(char** grid, int gridSize, int* gridColSize) {

    int count = 0;

    for (int i = 0; i < gridSize; i++)
        for (int j = 0; j < *gridColSize; j++){
            if (grid[i][j] == '1'){
                count++;
                dfs(grid, i, j, gridSize, *gridColSize);
            }
        }

    return count;
} 