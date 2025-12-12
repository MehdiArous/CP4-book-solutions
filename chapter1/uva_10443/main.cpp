/*************************************
Created By Mehdi Arous 
**************************************/

#include <iostream>
#include <unordered_map>
#include <cstring>
#define repeat(nb) for (int i=0; i<nb; i++)
using namespace std;

int r, c, n;

unordered_map <char, char> life = {
    {'S', 'R'}, {'P', 'S'}, {'R', 'P'}
};

int compare(char& a, char& b){
    if ((a=='R' && b=='S') || (a=='S' && b=='R')){
        if (a=='R') return 1;
        else return 0;
    }
    if ((a=='S' && b=='P') || (a=='P' && b=='S')){
        if (a=='S') return 1;
        else return 0;
    }
    if ((a=='P' && b=='R') || (a=='R' && b=='P')){
        if (a=='P') return 1;
        else return 0;
    }
    return -1;
}

void solve(char (*x)[100]){
    bool occupied[100][100];
    repeat(n){
        memset(occupied, false, sizeof(occupied));
        // navigate row by row
        for (int i=0; i<r; i++){
            for (int j=0; j<c-1; j++){
                int comp = compare(x[i][j], x[i][j+1]);
                if (comp >= 0)  occupied[i][j+comp] = 1;
            }
        }
        // navigate column by column
        for (int j=0; j<c; j++){
            for (int i=0; i<r-1; i++){
                int comp = compare(x[i][j], x[i+1][j]);
                if (comp >= 0)  occupied[i+comp][j] = 1;
            }
        }
        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++){
                if (occupied[i][j])
                    x[i][j] = life[x[i][j]];
            }
        }
    }
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            printf("%c", x[i][j]);
        }
        puts("");
    }
}

int main()
{
    int Tc;
    bool f = 0;
    scanf("%d", &Tc);
    while(Tc--){
        scanf("%d %d %d", &r, &c, &n);
        char board[100][100];
        repeat(r)
            scanf("%s", board[i]);
        if (f) puts("");
        solve(board);
        f = 1;
    }
    return 0;
}
