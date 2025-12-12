/*************************************
Created By Mehdi Arous 
**************************************/

#include <cstdio>

int a, b;

int max(){
    if (a > b) return a;
    else return b;
    return 0;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    while(scanf("%d %d", &a, &b) != EOF){
        if (a == b) printf("%d\n", a);
        else printf("%d\n", max());
    }
    return 0;
}