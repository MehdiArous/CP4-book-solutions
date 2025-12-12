/*************************************
Created By Mehdi Arous 
**************************************/

#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int Tc;
    while(scanf("%d", &Tc), Tc != -1){
        char puzzle[500], guess[500];
        int letters = 0;
        unordered_map<char, int> occ;
        unordered_map<char, int> falseGuess;
        scanf("%s %s", puzzle, guess);
        for (int i=0; puzzle[i]; i++){
            if (occ[puzzle[i]] == 0){
                occ[puzzle[i]] = 1;
                ++letters;
            }
        }
        unordered_map<char, int> secret = occ;
        int win = letters, hangman = 7;
        bool winnerflag = 0;
        for (int i=0; guess[i]; i++){
            if (occ[guess[i]] == 1) {
                --win;
                if (win == 0){
                    winnerflag = 1;
                    break;
                }
                occ[guess[i]] = 0;
            }
            else {
                if (falseGuess[guess[i]] == 0 && secret[guess[i]] == 0){
                    falseGuess[guess[i]] = 1;
                    --hangman;
                }
            }
        }
        if ( winnerflag && hangman > 0) printf("Round %d\nYou win.\n", Tc);
        else if (hangman <= 0) printf("Round %d\nYou lose.\n", Tc);
        else printf("Round %d\nYou chickened out.\n", Tc);
    }
    return 0;
}
