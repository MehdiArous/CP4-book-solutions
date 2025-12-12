/*************************************
Created By Mehdi Arous 
**************************************/

#include <iostream>
#include <cstring>
#define inRange(x) (x >= 0 && x <= 7)
using namespace std;

char chessBoard[8][8];

void debug(){
    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){
            printf("%c", chessBoard[i][j]);
        }
        puts("");
    }
}

int solve(){
    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){
            int x=j, y=i;
            char piece = chessBoard[i][j];
            // pawn case
            if (piece == 'p' || piece == 'P'){
                int c = -1;
                if (piece == 'p') c = 1;
                if (inRange(i+c) && inRange(j-1) && (chessBoard[i+c][j-1] == '.' || chessBoard[i+c][j-1] == '*'))
                    chessBoard[i+c][j-1] = '*';
                if (inRange(i+c) && inRange(j+1) && (chessBoard[i+c][j+1] == '.' || chessBoard[i+c][j+1] == '*'))
                    chessBoard[i+c][j+1] = '*';
            }
            // knight case
            if (piece == 'n' || piece == 'N'){
                int xKnight[8] = {x+2, x+1, x-1, x-2, x-2, x-1, x+1, x+2};
                int yKnight[8] = {y-1, y-2, y-2, y-1, y+1, y+2, y+2, y+1};
                for (int k=0; k<8; k++){
                    if (inRange(xKnight[k]) && inRange(yKnight[k]) && (chessBoard[yKnight[k]][xKnight[k]] == '*' || chessBoard[yKnight[k]][xKnight[k]] == '.'))
                        chessBoard[yKnight[k]][xKnight[k]] = '*';
                }
            }
            // King case 
            if (piece == 'k' || piece == 'K'){
                int xKing[8] = {x-1, x, x+1, x-1, x+1, x-1, x+1, x};
                int yKing[8] = {y-1, y-1, y-1, y, y, y+1, y+1, y+1};
                for (int k=0; k<8; k++){
                    if (inRange(xKing[k]) && inRange(yKing[k]) && (chessBoard[yKing[k]][xKing[k]] == '*' || chessBoard[yKing[k]][xKing[k]] == '.'))
                        chessBoard[yKing[k]][xKing[k]] = '*';
                }
            }
            // Bishop and Queen case (diagonals)
            if (piece == 'q' || piece == 'Q' || piece == 'b' || piece == 'B'){
                bool sw = 1, nw = 1, se = 1, ne = 1;
                int c = 1;
                while(sw||nw||se||ne) {
                    if (sw) {
                        if (inRange(x-c) && inRange(y+c) && (chessBoard[y+c][x-c] == '.' || chessBoard[y+c][x-c] == '*'))
                            chessBoard[y+c][x-c] = '*';
                        else sw = 0;
                    }
                    if (nw) {
                        if (inRange(x-c) && inRange(y-c) && (chessBoard[y-c][x-c] == '.' || chessBoard[y-c][x-c] == '*'))
                            chessBoard[y-c][x-c] = '*';
                        else nw = 0;
                    }
                    if (se) {
                        if (inRange(x+c) && inRange(y+c) && (chessBoard[y+c][x+c] == '.' || chessBoard[y+c][x+c] == '*'))
                            chessBoard[y+c][x+c] = '*';
                        else se = 0;
                    }
                    if (ne) {
                        if (inRange(x+c) && inRange(y-c) && (chessBoard[y-c][x+c] == '.' || chessBoard[y-c][x+c] == '*'))
                            chessBoard[y-c][x+c] = '*';
                        else ne = 0;
                    }
                    ++c;
                }
            }
            // Rook and Queen case (vertical)
            if (piece == 'q' || piece == 'Q' || piece == 'r' || piece == 'R'){
                bool north = 1, south = 1;
                int c = 1;
                while(north || south) {
                    if (north) {
                        if (inRange(x) && inRange(y-c) && (chessBoard[y-c][x] == '.' || chessBoard[y-c][x] == '*'))
                            chessBoard[y-c][x] = '*';
                        else north = 0;
                    }
                    if (south) {
                        if (inRange(x) && inRange(y+c) && (chessBoard[y+c][x] == '.' || chessBoard[y+c][x] == '*'))
                            chessBoard[y+c][x] = '*';
                        else south = 0;
                    }
                    ++c;
                }
            }
            // Rook and Queen case (horizontal)
            if (piece == 'q' || piece == 'Q' || piece == 'r' || piece == 'R'){
                bool east = 1, west = 1;
                int c = 1;
                while(east || west) {
                    if (east) {
                        if (inRange(x+c) && inRange(y) && (chessBoard[y][x+c] =='.' || chessBoard[y][x+c] =='*'))
                            chessBoard[y][x+c] = '*';
                        else east = 0;
                    }
                    if (west) {
                        if (inRange(x-c) && inRange(y) && (chessBoard[y][x-c] == '.' || chessBoard[y][x-c] == '*'))
                            chessBoard[y][x-c] = '*';
                        else west = 0;
                    }
                    ++c;
                }
            }
        } 
    }
    //debug();
    int ans = 0;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (chessBoard[i][j] == '.') ++ans;
        }
    }
    return ans;
}

int main()
{
    char FEN[100];
    while(scanf("%s", FEN) != EOF){
        int i = 0, j = 0;
        memset(chessBoard, '.', sizeof(chessBoard));
        for (int k=0; FEN[k]; k++){
            if (FEN[k] == '/') {
                ++i;
                j = 0;
            }
            else {
                if ((int)FEN[k] < 65) 
                    j += (FEN[k] - '0');
                else {
                    chessBoard[i][j] = FEN[k];
                    ++j;
                }
            }
        }
        printf("%d\n", solve());
        //debug();
    }
    return 0;
}