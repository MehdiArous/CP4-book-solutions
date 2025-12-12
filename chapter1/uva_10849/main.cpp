/*************************************
Created By Mehdi Arous 
**************************************/

#include <iostream>
using namespace std;

int r0, c0, r1, c1;

void solve() {
    
    if (r0==r1 && c0==c1)
        puts("0");
    else if (!((r0+r1)%2 == (c0+c1)%2))
        puts("no move");
    else {
        if (abs(r1-r0) == abs(c1-c0))
            puts("1");
        else puts("2");
    }
}

int main()
{
    int Tc, T, N;
    scanf("%d", &Tc);
    while(Tc--){
        scanf("%d %d", &T, &N);
        while(T--){
            scanf("%d %d %d %d", &r0, &c0, &r1, &c1);
            solve();
        }
    }
    return 0;
}
