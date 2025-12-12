/*************************************
Created By Mehdi Arous 
**************************************/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);
    int n, k, P1, P2;
    bool f = 0;
    char move1[10], move2[10];
    while(scanf("%d", &n), n){
        if (f) puts("");
        int loses[n+1], wins[n+1];
        memset(loses, 0, sizeof(loses));
        memset(wins, 0, sizeof(wins));
        scanf("%d", &k);
        for (int i=0; i<n*k*(n-1)/2; i++){
            scanf("%d %s %d %s", &P1, move1, &P2, move2);
            if (strcmp(move1, move2) != 0){
                if (move1[0] == 'r' && move2[0] == 's'){
                    ++wins[P1], ++loses[P2];
                }
                else if (move1[0] == 's' && move2[0] == 'r'){
                    ++wins[P2], ++loses[P1];
                }
                else if (move1[0] == 'r' && move2[0] == 'p'){
                    ++wins[P2], ++loses[P1];
                }
                else if (move1[0] == 'p' && move2[0] == 'r'){
                    ++wins[P1], ++loses[P2];
                }
                else if (move1[0] == 'p' && move2[0] == 's'){
                    ++wins[P2], ++loses[P1];
                }
                else if (move1[0] == 's' && move2[0] == 'p'){
                    ++wins[P1], ++loses[P2];
                }
            }
        }
        for (int p=1; p<=n; p++){
            if (loses[p] == 0 && wins[p] == 0)
                puts("-");
            else 
                printf("%.3lf\n", (double)(wins[p]) / (wins[p] + loses[p]));
        }
        f = 1;
    }
}