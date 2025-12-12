/*************************************
Created By Mehdi Arous 
**************************************/

#include <iostream>
#include <cstring>
using namespace std;

int King[8][8];
int Queen[8][8];
int posK, posQ, fPosQ;

void debug() {
    for (int i=0; i<=7; i++){
        for (int j=0; j<=7; j++){
            printf("%d ", Queen[i][j]);
        }
        puts("");
    }
}

void moves() {
    
    int i1, j1, i2, j2;
    i1 = posK / 8, j1 = posK % 8;
    if (i1-1 >= 0) King[i1-1][j1] = 1;
    if (i1+1 <= 7) King[i1+1][j1] = 1;
    if (j1-1 >= 0) King[i1][j1-1] = 1;
    if (j1+1 <= 7) King[i1][j1+1] = 1;
    
    i2 = posQ / 8, j2 = posQ % 8;
    
    for (int k=i2+1; k<=7; k++){
        if (8*k+j2==posK) break;
        if (King[k][j2] == 1){
            King[k][j2] = -1, Queen[k][j2] = -1;
            if (j1 == j2) break;
        }
        else Queen[k][j2] = 1;
    }
    for (int k=i2-1; k>=0; k--){
        if (8*k+j2==posK) break;
        if (King[k][j2] == 1){
            King[k][j2] = -1, Queen[k][j2] = -1;
            if (j1 == j2) break;
        }
        else Queen[k][j2] = 1;
    }

    for (int k=j2+1; k<=7; k++){
        if (8*i2+k==posK) break;
        if (King[i2][k] == 1){
            King[i2][k] = -1, Queen[i2][k] = -1;
            if (i1 == i2) break;
        }
        else Queen[i2][k] = 1;
    }
    for (int k=j2-1; k>=0; k--){
        if (8*i2+k==posK) break;
        if (King[i2][k] == 1){
            King[i2][k] = -1, Queen[i2][k] = -1;
            if (i1 == i2) break;
        }
        else Queen[i2][k] = 1;
    }
    return;
}

int main()
{
    while(scanf("%d %d %d", &posK, &posQ, &fPosQ) != EOF) {
        
        memset(King, 0, sizeof(King));
        memset(Queen, 0, sizeof(Queen));
        //debug();
        if (posK == posQ) {
            printf("Illegal state\n");
            continue;
        }
        moves();
        int i, j;
        i = fPosQ/8, j = fPosQ%8;
        if (Queen[i][j] == 0) printf("Illegal move\n");
        else if (Queen[i][j] == -1) printf("Move not allowed\n");
        else {
            bool test =(fPosQ==49 && posK==56) || (fPosQ==54 && posK==63) || (fPosQ==14 && posK==7) || (fPosQ==9 && posK==0);
            if (test) printf("Stop\n");
            else printf("Continue\n");
        }
        //debug();
    }
    return 0;
}