/*************************************
Created By Mehdi Arous 
**************************************/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <bitset>
using namespace std;

int dieThrows[1000];
bitset<100> stop;
bitset<100> again;

int main()
{
    int idx = 0, nbPlayers, to, from, square;
    while(scanf("%d", &dieThrows[idx]), dieThrows[idx])
        ++idx;
    while(scanf("%d", &nbPlayers), nbPlayers){
        unordered_map<int, int> chutesLadders;
        while(scanf("%d %d",&to, &from), to||from)
            chutesLadders[to] = from;
        while(scanf("%d", &square), square){
            if (square < 0) stop[abs(square)] = 1;
            else again[square] = 1;
        }
        // initialize positions of players to 0
        vector<int> posPlayer(nbPlayers);
        vector<bool> cantPlay(nbPlayers);
        for (int i=0; i<nbPlayers; i++){
            posPlayer[i] = 0;
            cantPlay[i] = 0;
        }
        // 
        bool endGame=0;
        int idPlayer = 0, idDice = 0;
        while(!(endGame)){
            if (!(cantPlay[idPlayer])){
                do {
                    //printf("%d %d\n", posPlayer[0], posPlayer[1]);
                    posPlayer[idPlayer] += dieThrows[idDice];
                    if (posPlayer[idPlayer] > 100) posPlayer[idPlayer] -= dieThrows[idDice];
                    if (posPlayer[idPlayer] == 100) endGame = 1;
                    if (chutesLadders[posPlayer[idPlayer]])
                        posPlayer[idPlayer] = chutesLadders[posPlayer[idPlayer]];
                    if (stop[posPlayer[idPlayer]])
                        cantPlay[idPlayer] = 1;
                    ++idDice;
                }   while(again[posPlayer[idPlayer]]);
            }
            else cantPlay[idPlayer] = 0;
            ++idPlayer;
            if (idPlayer == nbPlayers) idPlayer = 0;
        }
        //printf("%d %d\n", posPlayer[0], posPlayer[1]);
        for (int i=0; i<nbPlayers; i++){
            if (posPlayer[i] == 100){
                printf("%d\n", i+1);
                break;
            }
        }
        again.reset(), stop.reset();
    }
    return 0;
}