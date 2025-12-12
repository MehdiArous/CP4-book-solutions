/*************************************
Created By Mehdi Arous 
**************************************/

#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

char hand[15];

unordered_map <char, int> convertLetter = {
    {'A', 0}, {'T', 9}, {'J', 10},
    {'Q', 11}, {'K', 12}
};

int gain(int* hist){
    int runLen0 = -1, runLen1 = -1;
    int copyHist[13]; 
    for (int i=0; i<13; i++)
        copyHist[i] = hist[i];
    while (true){ 
        int start = 1, end = 12;
        bool found = false;
        if (copyHist[0]){
            int r = 0;
            while(copyHist[end] || copyHist[start]){
                if (copyHist[end]){
                    --copyHist[end], --end, ++r;}
                if (copyHist[start]){
                    --copyHist[start], ++start, ++r;}
            }
            if (r > 0){
                --copyHist[0];
                if (runLen0 != -1){
                    runLen1 = r+1, found=true;}
                else{
                    runLen0 = r+1, found=true;}
            }
            --end, ++start;
        }
        while(start < end){
            int r = 0;
            while(copyHist[start] && start <= end){
                --copyHist[start], ++start, ++r;
            }
            ++start;
            if (r > 1){
                if (runLen0 != -1){
                    runLen1 = r, found=true;} 
                else{
                    runLen0 = r, found=true;} 
            }
        }
        if (!found) break;
    }
    if (runLen0 == 5) return 100;
    if (runLen0 == 4) return 10;
    if (runLen0 + runLen1 == 5) return 5;
    if (runLen0 == 3) return 3;
    if (runLen0 + runLen1 == 4) return 1;
    return 0;
}

void solve(int* cardsHist){
    int firstHand = gain(cardsHist);
    int copyHist[13], bestCardEx;
    double bestExchange = 0.0;

    for (int i=0; i<13; i++){
        if (cardsHist[i]){
            memset(copyHist, 0, sizeof(copyHist));
            for (int i=0; i<13; i++)
                copyHist[i] = cardsHist[i];
            double exchangeGain = 0.0;
            --copyHist[i];
            for (int j=0; j<13; j++){
                ++copyHist[j];
                exchangeGain += ((4-cardsHist[j])*gain(copyHist) / 47.0);
                --copyHist[j];
            }
            if (bestExchange < exchangeGain){
                bestExchange = exchangeGain, bestCardEx = i;}
        }
    }
    if (bestExchange - 2 > firstHand - 1){
        for (int j=0; j<15; j+=3){
            char c = hand[j];
            if (c >= 65){
                if (bestCardEx == convertLetter[c]) {
                    printf("Exchange %c%c\n", c, hand[j+1]);
                    return;
                }
            }
            else {
                if (bestCardEx == c-'1') {
                    printf("Exchange %c%c\n", c, hand[j+1]);
                    return;
                }
            }
        }
    }
    puts("Stay");
}

int main()
{
    int cardsHist[13];
    freopen("input.txt", "r", stdin);
    while(scanf("%[^\n]\n", hand), hand[0] != '#'){
        memset(cardsHist, 0, sizeof(cardsHist));
        for (int i=0; i<15; i+=3){
            char c = hand[i];
            if (c >= 65)
                ++cardsHist[convertLetter[c]];
            else 
                ++cardsHist[c - '1'];
        }
        solve(cardsHist);
    }
    return 0;
}
