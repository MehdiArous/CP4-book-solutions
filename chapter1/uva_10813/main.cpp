/*************************************
Created By Mehdi Arous 
**************************************/

#include <iostream>
#include <cstring>
using namespace std;

bool numbers[76];
int card[5][5], number, ans;

bool bingo(){
    
    bool found = 0;
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            if (card[i][j] == number){
                card[i][j] = 0;
                found = 1;
                break;
            } 
        }
        if (found) break;
    }
    // check lines 
    for (int i=0; i<5; i++){
        if (!(card[i][0]||card[i][1]||card[i][2]||card[i][3]||card[i][4])) return 1;
    }
    // check columns 
    for (int i=0; i<5; i++){
        if (!(card[0][i]||card[1][i]||card[2][i]||card[3][i]||card[4][i])) return 1;
    }
    // check the two diagonals
    bool diag1, diag2;
    diag1 = !(card[0][0]||card[1][1]||card[2][2]||card[3][3]||card[4][4]);
    diag2 = !(card[4][0]||card[3][1]||card[2][2]||card[1][3]||card[0][4]);
    if (diag1 || diag2) return 1;
    return 0;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    while(n--){
        memset(numbers, 0, sizeof(numbers));
        memset(card, 0, sizeof(card));
        for (int i=0; i<5; i++){
            for (int j=0; j<5; j++){
                if (i==2 && j==2) continue;
                else {
                    scanf("%d", &number);
                    card[i][j] = number;
                    numbers[number] = 1;
                }
            }
        }
        bool endGame = 0;
        for (int i=0; i<75; i++){
            scanf("%d", &number);
            if (!endGame){
                if (numbers[number]){
                    if (bingo()) {
                        ans = i+1, endGame = 1; 
                    }
                }
            }    
        }
        printf("BINGO after %d numbers announced\n", ans);
    }
    return 0;
}