/*************************************
Created By Mehdi Arous 
**************************************/

#include <bits/stdc++.h>
using namespace std;

#define li long int 
const li N = 100000;

bool Alice[N+1];
bool Betty[N+1];

int main()
{
    int A, B;
    li X;
    
    while(scanf("%d %d", &A, &B), A||B){
        memset(Alice, false, sizeof(Alice));
        memset(Betty, false, sizeof(Betty));
        int a=0, b=0;
        li max_xi_yi = 0;
        while(A--){
            scanf("%ld", &X);
            if (X > max_xi_yi) max_xi_yi = X;
            if (!Alice[X]) {
                Alice[X] = 1;
                ++a;
            }
        }
        while(B--){
            scanf("%ld", &X);
            if (X > max_xi_yi) max_xi_yi = X;
            if (!Betty[X]){
                Betty[X] = 1;
                ++b;
            }
        }
        for (li i = 1; i<= max_xi_yi; i++){
            if (Betty[i] && Alice[i]){
                --a, --b;
            }
        }
        printf("%d\n", min(a, b));
    }
    return 0;
}