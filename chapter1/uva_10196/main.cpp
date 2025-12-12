/*************************************
Created By Mehdi Arous 
**************************************/

#include <iostream>
#include <cstring>
#define inRange(x) (x >= 0 && x <= 7)

using namespace std;

char board[8][8];
int xWhiteKing, yWhiteKing, xBlackKing, yBlackKing;

int checkTheCheck(bool isWhite) {
    int x, y;
    if (isWhite) {
        x = xWhiteKing, y = yWhiteKing;
    }
    else {
        x = xBlackKing, y = yBlackKing;
    }
    // Knight attacking case 
    int xKnight[8] = {x+2, x+1, x-1, x-2, x-2, x-1, x+1, x+2};
    int yKnight[8] = {y-1, y-2, y-2, y-1, y+1, y+2, y+2, y+1};
    for (int i=0; i<8; i++){
        if (inRange(xKnight[i]) && inRange(yKnight[i])){
            if (board[yKnight[i]][xKnight[i]] == 'n' && isWhite) return 1;
            if (board[yKnight[i]][xKnight[i]] == 'N' && !isWhite) return -1;
        }
    } 
    // pawn attacking case
    if (inRange(y-1)){
        if (inRange(x-1)){
            if (board[y-1][x-1] == 'p' && isWhite) return 1;
        }
        if (inRange(x+1)){
            if (board[y-1][x+1] == 'p' && isWhite) return 1;
        }
    }
    if (inRange(y+1)){
        if (inRange(x-1)){
            if (board[y+1][x-1] == 'P' && !isWhite) return -1;
        }
        if (inRange(x+1)){
            if (board[y+1][x+1] == 'P' && !isWhite) return -1;
        }
    }
    // Bishop, Rook and Queen case
    // diagonals
    bool sw = 1, nw = 1, se = 1, ne = 1;
    int i = 1;
    while(sw||nw||se||ne) {
        if (sw) {
            bool noAttack1 = (board[y+i][x-i] == 'r' || board[y+i][x-i] == 'p' || board[y+i][x-i] == 'k' || board[y+i][x-i] == 'n');
            bool noAttack2 = (board[y+i][x-i] == 'R' || board[y+i][x-i] == 'P' || board[y+i][x-i] == 'K' || board[y+i][x-i] == 'N');
            if (inRange(x-i) && inRange(y+i)){
                if (isWhite && (board[y+i][x-i] == 'q' || board[y+i][x-i] == 'b'))
                    return 1;
                if (!isWhite && (board[y+i][x-i] == 'Q' || board[y+i][x-i] == 'B'))
                    return -1;
                if (isWhite && (((int)board[y+i][x-i] > 65 && (int)board[y+i][x-i] < 97) || noAttack1))
                    sw = 0;
                if (!isWhite && (((int)board[y+i][x-i] > 97 && (int)board[y+i][x-i] < 122) || noAttack2))
                    sw = 0;
            }
            else sw = 0;
        }
        if (nw) {
            bool noAttack1 = (board[y-i][x-i] == 'r' || board[y-i][x-i] == 'p' || board[y-i][x-i] == 'k' || board[y-i][x-i] == 'n');
            bool noAttack2 = (board[y-i][x-i] == 'R' || board[y-i][x-i] == 'P' || board[y-i][x-i] == 'K' || board[y-i][x-i] == 'N');
            if (inRange(x-i) && inRange(y-i)){
                if (isWhite && (board[y-i][x-i] == 'q' || board[y-i][x-i] == 'b'))
                    return 1;
                if (!isWhite && (board[y-i][x-i] == 'Q' || board[y-i][x-i] == 'B'))
                    return -1;
                if (isWhite && (((int)board[y-i][x-i] > 65 && (int)board[y-i][x-i] < 97) || noAttack1))
                    nw = 0;
                if (!isWhite && (((int)board[y-i][x-i] > 97 && (int)board[y-i][x-i] < 122) || noAttack2))
                    nw = 0;
            }
            else nw = 0;
        }
        if (se) {
            bool noAttack1 = (board[y+i][x+i] == 'r' || board[y+i][x+i] == 'p' || board[y+i][x+i] == 'k' || board[y+i][x+i] == 'n');
            bool noAttack2 = (board[y+i][x+i] == 'R' || board[y+i][x+i] == 'P' || board[y+i][x+i] == 'K' || board[y+i][x+i] == 'N');
            if (inRange(x+i) && inRange(y+i)){
                if (isWhite && (board[y+i][x+i] == 'q' || board[y+i][x+i] == 'b'))
                    return 1;
                if (!isWhite && (board[y+i][x+i] == 'Q' || board[y+i][x+i] == 'B'))
                    return -1;
                if (isWhite && (((int)board[y+i][x+i] > 65 && (int)board[y+i][x+i] < 97) || noAttack1))
                    se = 0;
                if (!isWhite && (((int)board[y+i][x+i] > 97 && (int)board[y+i][x+i] < 122) || noAttack2))
                    se = 0;
            }
            else se = 0;
        }
        if (ne) {
            bool noAttack1 = (board[y-i][x+i] == 'r' || board[y-i][x+i] == 'p' || board[y-i][x+i] == 'k' || board[y-i][x+i] == 'n');
            bool noAttack2 = (board[y-i][x+i] == 'R' || board[y-i][x+i] == 'P' || board[y-i][x+i] == 'K' || board[y-i][x+i] == 'N');
            if (inRange(x+i) && inRange(y-i)){
                if (isWhite && (board[y-i][x+i] == 'q' || board[y-i][x+i] == 'b'))
                    return 1;
                if (!isWhite && (board[y-i][x+i] == 'Q' || board[y-i][x+i] == 'B'))
                    return -1;
                if (isWhite && (((int)board[y-i][x+i] > 65 && (int)board[y-i][x+i] < 97) || noAttack1))
                    ne = 0;
                if (!isWhite && (((int)board[y-i][x+i] > 97 && (int)board[y-i][x+i] < 122) || noAttack2))
                    ne = 0;
            }
            else ne = 0;
        }
        ++i;
    }
    // Horizontal 
    bool east = 1, west = 1;
    i = 1;
    while(east||west) {
        if (east) {
            bool noAttack1 = (board[y][x+i] == 'b' || board[y][x+i] == 'p' || board[y][x+i] == 'k'  || board[y][x+i] == 'n');
            bool noAttack2 = (board[y][x+i] == 'B' || board[y][x+i] == 'P' || board[y][x+i] == 'K'  || board[y][x+i] == 'N');
            if (inRange(x+i) && inRange(y)){
                if (isWhite && (board[y][x+i] == 'q' || board[y][x+i] == 'r'))
                    return 1;
                if (!isWhite && (board[y][x+i] == 'Q' || board[y][x+i] == 'R'))
                    return -1;
                if (isWhite && (((int)board[y][x+i] > 65 && (int)board[y][x+i] < 97) || noAttack1))
                    east = 0;
                if (!isWhite && (((int)board[y][x+i] > 97 && (int)board[y][x+i] < 122) || noAttack2))
                    east = 0;
            }
            else east = 0;
        }
        if (west) {
            bool noAttack1 = (board[y][x-i] == 'b' || board[y][x-i] == 'p' || board[y][x-i] == 'k'  || board[y][x-i] == 'n');
            bool noAttack2 = (board[y][x-i] == 'B' || board[y][x-i] == 'P' || board[y][x-i] == 'K'  || board[y][x-i] == 'N');
            if (inRange(x-i) && inRange(y)){
                if (isWhite && (board[y][x-i] == 'q' || board[y][x-i] == 'r'))
                    return 1;
                if (!isWhite && (board[y][x-i] == 'Q' || board[y][x-i] == 'R'))
                    return -1;
                if (isWhite && (((int)board[y][x-i] > 65 && (int)board[y][x-i] < 97) || noAttack1))
                    west = 0;
                if (!isWhite && (((int)board[y][x-i] > 97 && (int)board[y][x-i] < 122) || noAttack2))
                    west = 0;
            }
            else west = 0;
        }
        ++i;
    }
    
    // vertical 
    bool north = 1, south = 1;
    i = 1;
    while(north||south) {
        if (north) {
            bool noAttack1 = (board[y-i][x] == 'b' || board[y-i][x] == 'p' || board[y-i][x] == 'k'  || board[y-i][x] == 'n');
            bool noAttack2 = (board[y-i][x] == 'B' || board[y-i][x] == 'P' || board[y-i][x] == 'K'  || board[y-i][x] == 'N');
            if (inRange(x) && inRange(y-i)){
                if (isWhite && (board[y-i][x] == 'q' || board[y-i][x] == 'r'))
                    return 1;
                if (!isWhite && (board[y-i][x] == 'Q' || board[y-i][x] == 'R'))
                    return -1;
                if (isWhite && (((int)board[y-i][x] > 65 && (int)board[y-i][x] < 97) || noAttack1))
                    north = 0;
                if (!isWhite && (((int)board[y-i][x] > 97 && (int)board[y-i][x] < 122) || noAttack2))
                    north = 0;
            }
            else north = 0;
        }
        if (south) {
            bool noAttack1 = (board[y+i][x] == 'b' || board[y+i][x] == 'p' || board[y+i][x] == 'k'  || board[y+i][x] == 'n');
            bool noAttack2 = (board[y+i][x] == 'B' || board[y+i][x] == 'P' || board[y+i][x] == 'K'  || board[y+i][x] == 'N');
            if (inRange(x) && inRange(y+i)){
                if (isWhite && (board[y+i][x] == 'q' || board[y+i][x] == 'r'))
                    return 1;
                if (!isWhite && (board[y+i][x] == 'Q' || board[y+i][x] == 'R'))
                    return -1;
                if (isWhite && (((int)board[y+i][x] > 65 && (int)board[y+i][x] < 97) || noAttack1))
                    south = 0;
                if (!isWhite && (((int)board[y+i][x] > 97 && (int)board[y+i][x] < 122) || noAttack2))
                    south = 0;
            }
            else south = 0;
        }
        ++i;
    }
    return 0;
}
int main()
{
    int c = 0;
    while(true){
        int checkEnd = 0;
        for (int i=0; i<8; i++){
            scanf("%s", board[i]);
            if (strcmp(board[i], "........") == 0) ++checkEnd;
            else {
                for (int j=0; j<8; j++){
                    if (board[i][j] == 'K') {
                        xWhiteKing = j, yWhiteKing = i;
                    }
                    else if (board[i][j] == 'k') {
                        xBlackKing = j, yBlackKing = i;
                    }
                }
            }
        }
        if (checkEnd == 8) break;
        int ans = checkTheCheck(1);
        if (ans) printf("Game #%d: white king is in check.\n", ++c);
        else {
            int ans = checkTheCheck(0);
            if (ans == -1) printf("Game #%d: black king is in check.\n", ++c);
            else printf("Game #%d: no king is in check.\n", ++c);
        }
    }
    return 0;
}