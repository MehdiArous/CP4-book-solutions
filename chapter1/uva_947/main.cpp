/*************************************
Created By Mehdi Arous 
**************************************/

#include <iostream>
#include <unordered_map>
#include <string>
#include <cstring>
#include <vector>
#define repeat(nb) for (int i=1; i<=nb; i++)
using namespace std;

unordered_map<int, char> intTochar = {
    {1, '1'}, {2, '2'}, {3, '3'}, {4, '4'},
    {5, '5'}, {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'}
};

unordered_map<int, vector<string>> codes;

void gen_codes(){
    string st = "  ";
    repeat(9){
        st[0] = intTochar[i];
        repeat(9){
            st[1] = intTochar[i];
            codes[2].push_back(st);
        }
    }
    for (int j=0; j<codes[2].size(); j++){
        repeat(9)
            codes[3].push_back(codes[2][j]+intTochar[i]);
    }
    for (int j=0; j<codes[3].size(); j++){
        repeat(9)
            codes[4].push_back(codes[3][j]+intTochar[i]);
    }
    for (int j=0; j<codes[4].size(); j++){
        repeat(9)
            codes[5].push_back(codes[4][j]+intTochar[i]);
    }
}

int main()
{
    codes[2], codes[3], codes[4], codes[5];
    gen_codes();
    int Tc, n, strong, weak;
    char guess[5];
    scanf("%d", &Tc);
    while(Tc--){
        unordered_map <int, int> color = {
            {1, 0}, {2, 0}, {3, 0}, {4, 0},
            {5, 0}, {6, 0}, {7, 0}, {8, 0},
            {9, 0} };
        scanf("%s %d %d", guess, &strong, &weak);
        n = strlen(guess);
        for (int i=0; i<n; i++)
            ++color[guess[i]];
        vector <string> V = codes[n];
        int res = 0;
        for (int i=0; i<V.size(); i++){
            unordered_map <int, int> copyColor = color;
            int checkStrong = 0, checkWeak = 0;
            for (int j=0; j<n; j++){
                if (guess[j] == V[i][j]){
                    ++checkStrong;
                    --copyColor[V[i][j]];
                }
            }
            for (int j=0; j<n; j++){
                if (guess[j] != V[i][j]){
                    if (copyColor[V[i][j]] > 0){
                        ++checkWeak;
                        --copyColor[V[i][j]];
                    }
                } 
            }
            if (checkWeak == weak && checkStrong == strong) ++res;
        }
        printf("%d\n", res);
    }
    return 0;
}

// this solution runs in 1.2 sec.  / another github solution runs in 0.2 sec. 

