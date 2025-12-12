/*************************************
Created By Mehdi Arous 
**************************************/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int commands;
    while (scanf("%d", &commands), commands!=0){
        char command[6];
        int top = 1, north = 2, west = 3;
        while (commands--){
            scanf("%s", command);
            if (strcmp(command, "north") == 0){
                int copyNorth = top, copyTop = 7-north;
                top = copyTop;
                north = copyNorth;
            }
            else if (strcmp(command, "south") == 0){
                int copyNorth = 7-top, copyTop = north;
                top = copyTop;
                north = copyNorth;
            }
            else if (strcmp(command, "west") == 0){
                int copyWest = top, copyTop = 7-west;
                top = copyTop;
                west = copyWest;
            }
            else if (strcmp(command, "east") == 0){
                int copyWest = 7-top, copyTop = west;
                top = copyTop;
                west = copyWest;
            }
        }
        printf("%d\n", top);
    }
    return 0;
}