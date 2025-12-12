/*************************************
Created By Mehdi Arous 
**************************************/

#include <iostream>
#include <cstring>
using namespace std;

int cards[13];

int main()
{
    int a, b, c;
    //freopen("input.txt", "r", stdin);
    while (scanf("%d %d %d", &a, &b, &c), a||b||c) {
        memset(cards, 0, sizeof(cards));
        ++cards[a-1], ++cards[b-1], ++cards[c-1];
        if (a != b && b != c && a != c) puts("1 1 2");
        else if (a == 13 && b == 13 && c == 13) puts("*");
        else if (a == b && b == c && a < 13) printf("%d %d %d\n", a+1, a+1, a+1);
        else if (cards[12] == 2 && cards[11] == 1) puts("1 1 1");
        else if (cards[12] == 1 && cards[0] == 2) puts("1 2 2");
        else {
            memset(cards, 0, sizeof(cards));
            ++cards[a-1], ++cards[b-1], ++cards[c-1];
            bool found = 0;
            // check for 1 occurence first
            for (int i=0; i<13; i++){
                if (cards[i] == 1){
                    if (cards[(i+1)%13] == 0){
                        cards[i] = 0, cards[(i+1)%13] = 1;
                    }
                    else if (cards[(i+2)%13] == 0){
                        cards[i] = 0, cards[(i+2)%13] = 1;
                    }
                    if (i < 12) found = 1; 
                }
                if (found) break;
            }
            if (!found){
                // check for 2 occurence
                for (int i=0; i<13; i++){
                    if (cards[i] == 2){
                        found = 1;
                        cards[i] = 0, cards[i+1] = 2;
                    }
                    if (found) break;
                }
            }
            int j = 0;
            for (int i=0; i<13; i++){
                if (cards[i]){
                    while(cards[i]--){
                        ++j;
                        printf("%d", i+1);
                        if (j < 3) printf(" ");
                    }
                }
            }
            puts("");
        }
    }
    return 0;
}