#include <stdio.h>

#define size 6
#define blank ' '

void printboard(int board[size][size]) {
    for(int f=0;f<size;f++) {
        for(int c=0;c<size;c++) {
            char cell = board[f][c] == 0 ? blank : (board[f][c] == 1 ? 'X' : 'O');
            printf(" %c ",cell);
            if (c<size-1) {printf("|");}        
            }
        printf("\n");

        if (f<size-1) {
        for(int m=0;m<size;m++) {
            printf("---");
            if (m<size-1) {printf("+");}
        }
        printf("\n");
        }
    }
}

int playermove(int board[size][size],int player) {
    int f,c;
    printf("select your move player %d (enter two numbers ranging from 0-5)\n",player);
    scanf("%d %d",&f,&c);

    if (f>=0 && f<size && c>=0 && c<size && board[f][c]==0) {
        board[f][c]=player;
        return 1;
    } else printf("invalid move\n"); return 0;
}

int checkwin(int board[size][size], int player) {
    for(int f=0;f<size;f++) {
        int rowwin=1;
        for(int c=0;c<size;c++) {
            if (board[f][c] != player) {
                rowwin=0;
                break;
            }
        }
        if (rowwin) return 1;
    }

    for(int f=0;f<size;f++) {
        int colwin=1;
        for(int c=0;c<size;c++) {
            if (board[c][f] != player) {
                colwin=0;
                break;
            }
        }
        if (colwin) return 1;
    }

    int diagwin=1;
    for(int f=0;f<size;f++) {
        if(board[f][f]!=player) {
            diagwin=0;
            break;
        } 
    } if (diagwin) return 1;

    int diagwin1=1;
    for(int f=0;f<size;f++) {
        if(board[f][size-1-f]!=player) {
            diagwin1=0;
            break;
        }
    }
    if (diagwin1) return 1;

    return 0;
}


int main() {
    int board[size][size]={0},player=1,moves=0;
    const int totalmoves=size*size;

    while (moves<totalmoves) {
        printboard(board);
        if (playermove(board,player)) {
            moves++;
            if (checkwin(board,player)) {
                printboard(board);
                printf("player %d wins!\n",player); break;
            }
            player = (player == 1) ? 2 : 1;
        }
    }
    if (moves==totalmoves && !checkwin(board,player)) {
        printf("it's a draw :(");
    }
    return 0;
}