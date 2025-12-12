/*************************************
Created By Mehdi Arous 
**************************************/

#include <stdio.h>
#include <cstring>
using namespace std;

int const N = 18000 + 1;
int traffic[100][N];

void solve(int& x) {
    int hours, min, sec;
    hours = x / 3600, min = (x / 60) % 60;
    sec = x % 60;
    printf("0%d:", hours);
    if (min < 10) printf("0%d:", min);
    else printf("%d:", min);
    if (sec < 10) printf("0%d\n", sec);
    else printf("%d\n", sec);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int cycle;
    while(true) { 
        memset(traffic, 0, sizeof(traffic));
        int idx = 0;
        bool here = 0;
        while(scanf("%d", &cycle), cycle){
            here = 1;
            int i0 = 0;
            while(i0 < N) {
                for (int i=i0; i<i0+(cycle-5) && i<N; i++)
                    traffic[idx][i] = 1;
                i0 += (2*cycle);
            }
            ++idx;
        }
        if (!here) break;
        bool foundSol = 0;
        for (int j=1; j<N; j++){
            bool notFound = 0;
            int allOnes = 0;
            for (int i=0; i<idx; i++) {
                if (traffic[i][j] == 0){
                    notFound = 1;
                    break;    
                } 
                if (traffic[i][j] + traffic[i][j-1] == 2) 
                    ++allOnes;
            }
            if (allOnes < idx && !notFound) {
                solve(j), foundSol = 1;
                break;
            }
        }
        if (!foundSol) puts("Signals fail to synchronise in 5 hours");
    }
    return 0;
}