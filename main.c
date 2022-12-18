#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintBoard(int r, int c, int board[][c]){
    for(int i=0; i<c; i++)
        printf("  %d ",i+1);
    printf("\n");
    for(int i=0; i<c; i++)
        printf("____");
    printf("_\n");
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
        for(int i=0; i<c; i++){
            printf("____");
        }
        printf("_\n");
    }

}



int main()
{
    int r, c;
    printf("number of rows\n");
    scanf("%d", &r);
    printf("number of columns\n");
    scanf("%d", &c);
    int board[r][c];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            board[i][j] = 32;
        }
    }
    PrintBoard(r, c, board);
    for(int i=0; i<(r * c); i++){
        int col1 = 0, col2 = 0, found = 1;
        int row1 = r, row2 = r;
        printf("player 1 to play");
        scanf("%d", &col1);
        while(col1 > c){
            printf("unavailable\nplayer 1 to play");
            scanf("%d", &col1);
        }
        while(board[row1][col1-1] != 32){
            row1--;
        }
        board[row1][col1-1] = 88;
        PrintBoard(r, c, board);
        while(found){
            printf("player 2 to play");
            scanf("%d", &col2);
            while(col2 > c){
            printf("unavailable\nplayer 2 to play");
            scanf("%d", &col2);
            }
            while(board[row2][col2-1] != 32){
                row2--;
            }
            board[row2][col2-1] = 79;
            PrintBoard(r, c, board);
            found = 0;
        }

    }


    return 0;
}
