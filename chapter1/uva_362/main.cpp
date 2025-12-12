/*************************************
Created By Mehdi Arous 
**************************************/

#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int fileSize, packet, dataTr, timePassed, c = 0, t;
    //freopen("input.txt", "r", stdin);
    while (scanf("%d", &fileSize), fileSize){
        printf("Output for data set %d, %d bytes:\n", ++c, fileSize);
        dataTr = 0, timePassed = 0;
        while(fileSize > 0){
            scanf("%d", &packet);
            ++timePassed, dataTr += packet;
            fileSize -= packet;
            if (timePassed % 5 == 0){
                if (dataTr > 0) {
                    t = ceil(fileSize * 5.0 / dataTr);
                    printf("   Time remaining: %d seconds\n", t);
                }
                else printf("   Time remaining: stalled\n");
                dataTr = 0;
            }
        }
        printf("Total time: %d seconds\n\n", timePassed);
    }
    return 0;
}