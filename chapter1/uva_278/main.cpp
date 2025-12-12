/*************************************
Created By Mehdi Arous 
**************************************/

#include <iostream>
using namespace std;

int parity(int x) {
    if (x%2) return x/2 + 1;
    return x/2;
}

int main()
{
    int nbProblems, m, n, a, b, c;
    char chessPiece;
    
    scanf("%d", &nbProblems);
    while (nbProblems--) {
        scanf(" %c %d %d", &chessPiece, &m, &n);
        a = parity(n), b = parity(m), c = parity(m*n);
        if (chessPiece == 'r' || chessPiece == 'Q') printf("%d\n", min(m,n));
        else if (chessPiece == 'K') printf("%d\n", a*b);
        else printf("%d\n", c);
    }
    return 0;
}