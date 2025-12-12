/*************************************
Created By Mehdi Arous 
**************************************/

#include <iostream>
#include <unordered_map>
#include <cstring>
#define repeat(nb) for(int i=0; i<nb; i++)
using namespace std;

int main()
{
    int Tc, from, to, a, b, c, die;
    scanf("%d", &Tc);
    while(Tc--){
        unordered_map<int, int> snakeAndLadder;
        bool endGame = false;
        scanf("%d %d %d", &a, &b, &c);
        int* playerPosition = new int[a];
        for (int i = 0; i < a; ++i) 
            playerPosition[i] = 1;
        repeat(b){
            scanf("%d %d", &from, &to);
            snakeAndLadder[from] = to;
        }
        repeat(c){
            scanf("%d", &die);
            if (!endGame && a > 0){
                playerPosition[i%a] += die;
                if (snakeAndLadder[playerPosition[i%a]])
                    playerPosition[i%a] = snakeAndLadder[playerPosition[i%a]];
                if (playerPosition[i%a] >= 100){
                    endGame = 1;
                    playerPosition[i%a] = 100;
                } 
            }
        }
        repeat(a)
            printf("Position of player %d is %d.\n", i+1, playerPosition[i]);
        delete[] playerPosition;
    }
    return 0;
}
