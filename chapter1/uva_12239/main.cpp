/*************************************
Created By Mehdi Arous 
**************************************/

#include <iostream>
#include <bitset>
#define repeat(nb) for (int i=0; i<nb; i++)
using namespace std;

bitset<91> balls;

int main()
{
    int N, B;
    balls[0] = 1;
    while(scanf("%d %d", &N, &B), N||B){
        int* bag = new int[N+1];
        repeat(B)
            scanf("%d", &bag[i]);
        for (int i=0; i<B-1; i++){
            for (int j=i+1; j<B; j++)
                balls[abs(bag[i] - bag[j])] = 1;
        }
        if (balls.count() == N+1) puts("Y");
        else puts("N");
        balls.reset();
        balls[0] = 1;
        delete[] bag;
    }
    return 0;
}