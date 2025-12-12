/*************************************
Created By Mehdi Arous 
**************************************/

#include <stdio.h>
#include <unordered_map>
#include <cstring>
using namespace std;

unordered_map <char, int> noteIdx = {
    {'C', 0}, {'c', 1}, {'D', 2}, {'d', 3},
    {'E', 4}, {'F', 5}, {'f', 6}, {'G', 7},
    {'g', 8}, {'A', 9}, {'a', 10}, {'B', 11}
};

bool allNotes[12];
char notes [] = {'C', 'c', 'D', 'd', 'E', 'F', 'f', 'G', 'g', 'A', 'a', 'B'};

void solve() {
    bool majorScale [12], firstSol = 1;
    for (int i=0; notes[i]; i++){
        memset(majorScale, 0, sizeof(majorScale));
        majorScale[i%12] = 1, majorScale[(i+2)%12] = 1;
        majorScale[(i+4)%12] = 1, majorScale[(i+5)%12] = 1;
        majorScale[(i+7)%12] = 1, majorScale[(i+9)%12] = 1;
        majorScale[(i+11)%12] = 1;
        bool test = 1;
        for (int j=0; j<12; j++) {
            if (allNotes[j] && !majorScale[j]) test = 0;
        }
        if (test) {
            if (!firstSol) printf(" ");
            firstSol = 0;
            if (notes[i] > 90) printf("%c#", notes[i] - 32);
            else printf("%c", notes[i]);
        }
    }
    puts("");
}

int main()
{
    char note[1005];
    while (fgets(note, sizeof(note), stdin), note[1] != 'N') {
        memset(allNotes, 0, sizeof(allNotes));
        int idx = 0;
        while(note[idx]){
            char c = note[idx];
            if (note[idx+1] == '#'){
                allNotes[noteIdx[c + 32]] = 1;
                idx += 3;
            }
            else {
                allNotes[noteIdx[c]] = 1;
                idx += 2;
            }
        }
        solve();
    }
    return 0;
}
