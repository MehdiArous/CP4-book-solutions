/*************************************
Created By Mehdi Arous 
**************************************/

#include <iostream>
using namespace std;

int x1, y1, x2, y2;

void solve(){
    if (x1==x2 && y1==y2)
        puts("0");
    else if(x1==x2 || y1==y2 || (abs(x2-x1) == abs(y2-y1)))
        puts("1");
    else puts("2");
}

int main()
{
    while(scanf("%d %d %d %d", &x1, &y1, &x2, &y2), x1||x2||y1||y2)
        solve();

    return 0;
}