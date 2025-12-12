/*************************************
Created By Mehdi Arous 
**************************************/

#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;

bitset<11> high;
bitset<11> low;

int main()
{
    int guess;
    char response[10];
    while (scanf("%d", &guess), guess){
        getchar();
        fgets(response, sizeof(response), stdin);
        if (strncmp(response, "too high", 8) == 0)
            high[guess] = 1;
        else if (strncmp(response, "too low", 7) == 0)
            low[guess] = 1;
        else{
            bool cheat = 0;
            for (int i=1; i<=10; i++){
                if (high[i]){
                    if (guess >= i) cheat = 1;
                }
            }
            if (!cheat){
                for (int i=1; i<=10; i++){
                    if (low[i]){
                        if (guess <= i) cheat = 1;
                    }
                }
            }
            if (cheat) puts("Stan is dishonest");
            else puts("Stan may be honest");
            high.reset();
            low.reset();
        }
            
    }
    return 0;
}