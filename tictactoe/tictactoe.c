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
        for(int m=0;m<size;m++) {
            printf("---");
            if (m<size-1) {printf("+");}
        }
        printf("\n");
    }
}

int main() {
    int board[size][size];
    printboard(board);
    return 0;
}