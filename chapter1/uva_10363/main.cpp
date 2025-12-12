/*************************************
Created By Mehdi Arous 
**************************************/

#include <iostream>
using namespace std;

int xcord[] = {0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 0, 0, 1, 1, 1, 2, 2, 2, 0, 1, 2, 2, 1, 0};
int ycord[] = {0, 0, 0, 1, 1, 1, 2, 2, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2};

void solve(char (&x)[4][4]){
    int nbX = 0, nbO = 0, nbP = 0;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (x[i][j] == 'O') ++nbO;
            if (x[i][j] == 'X') ++nbX;
            if (x[i][j] == '.') ++nbP;
        }
    }
    if (nbX == nbO || nbX - nbO == 1){
        bool Xwin = 0, Owin = 0;
        for (int i=0; i<24; i+=3){
            int j0 = xcord[i], i0 = ycord[i];
            int j1 = xcord[i+1], i1 = ycord[i+1];
            int j2 = xcord[i+2], i2 = ycord[i+2];
            if ((x[i0][j0] == x[i1][j1]) && (x[i1][j1] == x[i2][j2])){
                if (x[i0][j0] == 'X') Xwin = 1;
                if (x[i0][j0] == 'O') Owin = 1;
            }
        }
        if ((Xwin && !Owin && (!nbP || nbX - nbO == 1)) || (!Xwin && Owin && nbX == nbO && nbP > 0) || (!Xwin && !Owin))
            puts("yes");
        else puts("no");
    }
    else puts("no");
}

int main(){
    //freopen("input.txt", "r", stdin);
    int Tc;
    char board[4][4];
    scanf("%d", &Tc);
    while(Tc--){
        for (int i=0; i<3; i++){
            scanf("%s", board[i]);
        }
        solve(board);
    }
}
