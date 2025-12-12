/*************************************
Created By Mehdi Arous 
**************************************/

#include <cstdio>

char keyBoard[4][14] = {
    {'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '='},
    {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']'},
    {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';'},
    {'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/'},
};

int main()
{
    keyBoard[1][12] = 92;
    keyBoard[2][10] = 39;
    //freopen("input.txt", "r", stdin);
    char key;
    while ((key = getchar()) != EOF){
        if (key == ' ' || key == '\n') printf("%c", key);
        else {
            bool found = 0;
            for (int i=0; i<4; i++){
                for (int j=1; keyBoard[i][j]; j++){
                    if (keyBoard[i][j] == key){
                        found = 1;
                        printf("%c", keyBoard[i][j-1]);
                        break;
                    }
                }
                if (found) break;
            }
        }
    }
    return 0;
}