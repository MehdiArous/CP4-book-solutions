/*************************************
Created By Mehdi Arous 
**************************************/

#include <iostream>
#include <unordered_map>
#include <cstring>
#define repeat(nb) for (int i=0; i<nb; i++)
using namespace std;

int main()
{
    int N, c = 0;
    while(scanf("%d", &N), N > 0){
        printf("Game %d:\n", ++c);
        int secret[N], guess[N];
        unordered_map <int, int> color = {
            {1, 0}, {2, 0}, {3, 0}, {4, 0},
            {5, 0}, {6, 0}, {7, 0}, {8, 0},
            {9, 0}
        };
        repeat(N){
            scanf("%d", &secret[i]);
            ++color[secret[i]];
        }
        
        while (true){
            int checkBreak = 0;
            unordered_map <int, int> colorCopy = color;
            int strong = 0, weak = 0; 
            bool checkStrong[N];
            memset(checkStrong, 0, sizeof(checkStrong));
            repeat(N){
                scanf("%d", &guess[i]);
                checkBreak += guess[i];
                if (guess[i] == secret[i]){
                    ++strong;
                    checkStrong[i] = 1;
                    --colorCopy[secret[i]];
                }
            }
            if (checkBreak == 0) break;
            repeat(N){
                if (!checkStrong[i]){
                    if (colorCopy[guess[i]] > 0){
                        ++weak;
                        --colorCopy[guess[i]];
                    }
                }
            }
            printf("    (%d,%d)\n", strong, weak);
        }
    }
    return 0;
}