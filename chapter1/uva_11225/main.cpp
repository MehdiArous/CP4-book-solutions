/*************************************
Created By Mehdi Arous 
**************************************/

#include <iostream>
#include <cstring>
using namespace std;

int oudler_score[4] = {56, 51, 41, 36};

int main()
{   
    int Tc, cards, c=0;
    scanf("%d", &Tc);
    while(Tc--){
        scanf("%d", &cards);
        getchar();
        float score = 0.0;
        int oudlers = 0;
        while(cards--){
            char card[50];
            fgets(card, sizeof(card), stdin);
            //getchar();
            if (strncmp("twenty-one", card, 10) == 0){
                score += 4.5; 
                ++oudlers;
            }
            else if (strncmp("fool", card, 4) == 0 || strncmp("one", card, 3) == 0){
                score += 4.5; 
                ++oudlers;
            }
            else if (strncmp("king", card, 4) == 0) score += 4.5;
            else if (strncmp("queen", card, 5) == 0) score += 3.5;
            else if (strncmp("knight", card, 6) == 0) score += 2.5;
            else if (strncmp("jack", card, 4) == 0) score += 1.5;
            else score += 0.5;
        }
        if (oudler_score[oudlers] > score){
            printf("Hand #%d\n", ++c);
            printf("Game lost by %0.f point(s).\n", oudler_score[oudlers] - score);
        }
        else {
            printf("Hand #%d\n", ++c);
            printf("Game won by %0.f point(s).\n", score - oudler_score[oudlers]);
        }
        if (Tc) puts("");
    }
    return 0;
}