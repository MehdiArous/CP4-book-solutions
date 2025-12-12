/*************************************
Created By Mehdi Arous 
**************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int Tc, c=0;
    
    scanf("%d", &Tc);
    getchar();
    
    while(Tc--){
        char pile[156];
        int y=0, p=3, removed_cards, idx=78, x, away_cards = 0;
        fgets(pile, sizeof(pile), stdin);
        getchar();

        while(p--){
            if (pile[idx] >= 65){
                removed_cards = 1;
                y += 10;
                away_cards += removed_cards;
            }
            else{
                x = pile[idx] - '0';
                y += x;
                removed_cards = (1 + 10 - x);
                away_cards += removed_cards;
            }
            idx -= (3*removed_cards);
        }
        int card = (y-1) * 3;
        if (card <= idx) printf("Case %d: %c%c\n", ++c, pile[card], pile[card+1]);
        else {
            card += (away_cards * 3);
            printf("Case %d: %c%c\n", ++c, pile[card], pile[card+1]);
        }
    }
    return 0;
}
