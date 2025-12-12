/*************************************
Created By Mehdi Arous 
**************************************/

#include <bits/stdc++.h>
using namespace std;

char cards_down[2][100], cards_up[2][100];
int pile_up[2], pile_down[2], length[2];

void snap(){
    
    int p;
    
    for (int i=0; i<1000; i++){
        
        if (pile_up[0] == 0 && pile_down[0] == 0){
            puts("John wins.");
            return;
        }
        if (pile_up[1] == 0 && pile_down[1] == 0){
            puts("Jane wins.");
            return;
        }        
        
        if (cards_down[0][length[0]-pile_down[0]] != cards_down[1][length[1]-pile_down[1]]){
            cards_up[0][pile_up[0]] = cards_down[0][length[0]-pile_down[0]];
            cards_up[1][pile_up[1]] = cards_down[1][length[1]-pile_down[1]];
            ++pile_up[0], ++pile_up[1];
            --pile_down[0], --pile_down[1];
        }
        else{
            cards_up[0][pile_up[0]] = cards_down[0][length[0]-pile_down[0]];
            cards_up[1][pile_up[1]] = cards_down[1][length[1]-pile_down[1]];
            ++pile_up[0], ++pile_up[1];
            --pile_down[0], --pile_down[1];
            p = random() / 141 % 2;
            for (int j=0; j<pile_up[1-p]; j++)
                cards_up[p][pile_up[p]+j] = cards_up[1-p][j];
            pile_up[p] += pile_up[1-p];
            pile_up[1-p] = 0;
            if (p) printf("Snap! for John: ");
            else printf("Snap! for Jane: ");
            for (int j=pile_up[p]-1; j>=0; j--)
                printf("%c", cards_up[p][j]);
            printf("\n");
        }
        
        if (!pile_down[0]){
            pile_down[0] = pile_up[0];
            for (int j=0; j<pile_up[0]; j++)
                cards_down[0][j] = cards_up[0][j];
            pile_up[0] = 0;
            length[0] = pile_down[0];
        }
        if (!pile_down[1]){
            pile_down[1] = pile_up[1];
            for (int j=0; j<pile_up[1]; j++)
                cards_down[1][j] = cards_up[1][j];
            pile_up[1] = 0;
            length[1] = pile_down[1];
        }
        
    }
    puts("Keeps going and going ...");
    return;
}

int main()
{
    int Tc;
    scanf("%d", &Tc);
    while(Tc--){
        scanf("%s %s", cards_down[0], cards_down[1]);
        length[0] = length[1] = pile_down[0] = pile_down[1] = strlen(cards_down[0]);
        pile_up[0] = pile_up[1] = 0;
        snap();
        if (Tc) puts("");
    }
    return 0;
}


