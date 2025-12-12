/*************************************
Created By Mehdi Arous 
**************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>
#define repeat(nb) for (int i = 0; i < nb; i++)
using namespace std;

int M, nbCols[10];

struct routingTable {
    char MTA[20];
    char C[20], ADMD[20], PRMD[20], O[20];
};

void solve(routingTable (&array)[10][10], unordered_map<string, int> &MTas, routingTable &mail, int idx) {

    int line = MTas[mail.MTA], newLine;
    int nbCol = nbCols[line];
    bool visited[10];
    memset(visited, false, sizeof(visited));
    visited[line] = true;
    char inNetworkMTA[20];
    strcpy(inNetworkMTA, mail.MTA);
    while (true) {
        int notFound = 0;
        for (int j = 0; j < nbCol; j++) {
            int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
            if(!(strcmp(mail.C, array[line][j].C))) a1 = 1;
            if (strcmp(array[line][j].C, "*") == 0) a1 = 1;
            if(!(strcmp(mail.ADMD, array[line][j].ADMD))) a2 = 1;
            if (strcmp(array[line][j].ADMD, "*") == 0) a2 = 1;
            if(!(strcmp(mail.PRMD, array[line][j].PRMD))) a3 = 1;
            if (strcmp(array[line][j].PRMD, "*") == 0) a3 = 1;
            if(!(strcmp(mail.O, array[line][j].O))) a4 = 1;
            if (strcmp(array[line][j].O, "*") == 0) a4 = 1;
            
            if (a1 * a2 * a3 * a4) {
                if (!(strcmp(inNetworkMTA, array[line][j].MTA))) {
                    printf("%d -- delivered to %s\n", idx, inNetworkMTA);
                    return;
                } else {
                    newLine = MTas[array[line][j].MTA];
                    strcpy(inNetworkMTA, array[line][j].MTA);
                    if (visited[newLine]) {
                        printf("%d -- circular routing detected by %s\n", idx, array[line][j].MTA);
                        return;
                    }
                    memset(visited, false, sizeof(visited));
                    visited[line] = 1;
                    break;
                }
            }
            ++notFound;
        }
        if (notFound == nbCol) {
            printf("%d -- unable to route at %s\n", idx, inNetworkMTA);
            return;
        }
        line = newLine, nbCol = nbCols[newLine];
    }
}

int main() {
    int nbMTAs, nbMessages, Tc = 0;
    char MTa[20];

    // Redirect stdin to read from input.txt
    //freopen("input.txt", "r", stdin);

    while (scanf("%d", &M) != EOF) {
        
        routingTable rTable[10][10];
        unordered_map<string, int> MTas;
        repeat(M) {
            scanf("%s %d", MTa, &nbMTAs);
            MTas[MTa] = i;
            nbCols[i] = nbMTAs;
            for (int j = 0; j < nbMTAs; j++) {
                scanf("%s", rTable[i][j].MTA);
                scanf("%s %s", rTable[i][j].C, rTable[i][j].ADMD);
                scanf("%s %s", rTable[i][j].PRMD, rTable[i][j].O);
            }
        }
        printf("Scenario # %d\n", ++Tc);
        scanf("%d", &nbMessages);
        routingTable mail;
        repeat(nbMessages) {
            scanf("%s %s %s %s %s", mail.MTA, mail.C, mail.ADMD, mail.PRMD, mail.O);
            solve(rTable, MTas, mail, i + 1);
        }
        puts("");
        memset(nbCols, 0, sizeof(nbCols));
    }
    return 0;
}