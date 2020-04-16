/*
On an 8 x 8 chessboard, there is one white rook.  There also may be empty squares, white bishops, and black pawns.  These are given as characters 'R', '.', 'B', and 'p' respectively. Uppercase characters represent white pieces, and lowercase characters represent black pieces.

The rook moves as in the rules of Chess: it chooses one of four cardinal directions (north, east, west, and south), then moves in that direction until it chooses to stop, reaches the edge of the board, or captures an opposite colored pawn by moving to the same square it occupies.  Also, rooks cannot move into the same square as other friendly bishops.

Return the number of pawns the rook can capture in one move.
*/

//@stime 2020-03-26 22:00

int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int row = boardSize;
    int col = *boardColSize;

    int sum = 0;
    int m = 0;
    printf("%d %d", row, col);
    //找R
    int i = 0, j = 0;
    for(i = 0; i < col; i++)
        for(j = 0; j < row; j++)
            if(board[i][j] == 'R')
                goto R;

R:

    for(m = i + 1;m < 8; m++){
        if(board[m][j] == '.')
            continue;
        else if(board[m][j] == 'B')
            break;
        sum += 1;
        break;
    }
    for(m = i - 1; m >= 0; m--){
        if(board[m][j] == '.')
            continue;
        else if(board[m][j] == 'B')
            break;
        sum += 1;
        break;
    }
    for(m = j + 1; m < 8; m++){
        if(board[i][m] == '.')
            continue;
        else if(board[i][m] == 'B')
            break;
        sum += 1;
        break;
    }
    for(m = j - 1; m >= 0; m--){
        if(board[i][m] == '.')
            continue;
        else if(board[i][m] == 'B')
            break;

        sum += 1;
        break;
    }
    return sum;
}