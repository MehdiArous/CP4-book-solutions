/*************************************
Created By Mehdi Arous 
**************************************/

#include <iostream>
#include <cstring>
using namespace std;

int frameScore(char& c1, char c2 = '0'){
    if (isdigit(c1) && isdigit(c2))
        return (c1 - '0') + (c2 - '0');
    else if (c1 == c2) return 20;
    else if (c2 == '/') return 10;
    else {
        if (isdigit(c1)) return (c1 - '0') + 10;
        else if (isdigit(c2)) return (c2 - '0') + 10;
    }
    return 0;
}

void solve(char* x){
    int length = strlen(x) - 1; // -2 if I use input here
    int score = 0, i=0, frame=0;
    while(i < length){
        if (x[i] == 'X'){
            score += (10 + frameScore(x[i+1], x[i+2]));
            ++i, ++frame;
        }
        else {
            if (x[i+1] == '/') score += (10 + frameScore(x[i+2]));
            else score += (frameScore(x[i], x[i+1]));
            i += 2, ++frame;
        }
        if (frame == 10) break;
    }
    printf("%d\n", score);
    
}

int main()
{
    //freopen("input.txt", "r", stdin);
    while (true){
        char game[25];
        int idx = 0;
        while((game[idx] = getchar()) != '\n'){
            if (game[idx] == ' ') --idx;
            ++idx;    
        }
        if (strncmp(game, "GameOver", 8) == 0) break;
        solve(game);
        memset(game, '\0', sizeof(game));
    }
    return 0;
}
