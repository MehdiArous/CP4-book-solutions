/*************************************
Created By Mehdi Arous 
**************************************/

#include <stdio.h>

int main() {
    int Tc, s, d;
    scanf("%d", &Tc);
    while(Tc--) {
        scanf("%d %d", &s, &d);
        int score1 = (s+d), score2 = (s-d);
        if (score1*score2 < 0 || score1%2 || score2%2)
            puts("impossible");
        else 
            printf("%d %d\n", score1/2, score2/2);
    }
}