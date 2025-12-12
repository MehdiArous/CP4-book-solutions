#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

string p1, p2, child;
int c;
vector<string> genes[4] = {{"OO"}, {"AA", "AO", "OA"}, {"BB", "BO", "OB"}, {"AB", "BA"}};
map<string, int> indices = {{"O", 0}, {"A", 1}, {"B", 2}, {"AB", 3}};
map<string, string> bloodType = {{"OO", "O"}, {"AO", "A"}, {"OA", "A"}, {"AA", "A"},
    {"BB", "B"}, {"BO", "B"}, {"OB", "B"}, {"AB", "AB"}, {"BA", "AB"}};

void solve()
{
    set<string> All_types;
    int l1 = p1.size() - 1, l2 = p2.size() - 1, lc = child.size() - 1;
    char rh1 = p1[l1], rh2 = p2[l2], rhc = child[lc];
    string b1 = p1.substr(0, l1), b2 = p2.substr(0, l2), bc = child.substr(0, lc);
    if (child == "?")
    {
        vector<string> v1 = genes[indices[b1]], v2 = genes[indices[b2]];
        for (string s1 : v1)
        {
            for (string s2 : v2)
            {
                for (char allele1 : s1)
                {
                    for (char allele2 : s2)
                    {
                        string babyBlood = "";
                        babyBlood += allele1;
                        babyBlood += allele2;
                        All_types.insert(bloodType[babyBlood]+'-');
                        if (rh1 != '-' || rh2 != '-')
                            All_types.insert(bloodType[babyBlood]+'+');
                    }
                }
            }
        }
        vector<string> types;
        for (set<string>::iterator it = All_types.begin(); it != All_types.end(); ++it)
            types.push_back(*it);
        cout << "Case " << ++c << ": " << p1 << " " << p2 << " ";
        if (All_types.size() == 1)
            cout << *(All_types.begin()) << "\n";
        else
        {
            cout << "{";
            for (int i=0; i<types.size()-1; i++)
                cout << types[i] << ", ";
            cout << types[types.size()-1] << "}\n";
        }
        return;
    }
    string parent = (p1 == "?" ? p2 : p1);
    vector<string> v1 = genes[indices[parent.substr(0, parent.size() - 1)]];
    for (string s1 : v1)
    {
        for (int i=0; i<4; i++)
        {
            vector<string> v2 = genes[i];
            for (string s2 : v2)
            {
                for (char allele1 : s1)
                {
                    for (char allele2 : s2)
                    {
                        string parentBlood = "";
                        parentBlood += allele1;
                        parentBlood += allele2;
                        if (bloodType[parentBlood] == bc)
                        {
                            All_types.insert(bloodType[s2]+'+');
                            if (!(parent[parent.size() - 1] == '-' && rhc == '+'))
                                All_types.insert(bloodType[s2]+'-');
                        }
                    }
                }
            }
        }
    }
    vector<string> types;
    for (set<string>::iterator it = All_types.begin(); it != All_types.end(); ++it)
        types.push_back(*it);
    cout << "Case " << ++c << ": " << (p1 == "?" ? "" : p1);
    if (p1 != "?") cout << " ";
    if (types.size() == 1)
        cout << " " <<  *(All_types.begin());
    else if (types.size() == 0)
        cout << " IMPOSSIBLE";
    else
    {
        cout << "{";
        for (int i=0; i<types.size()-1; i++)
            cout << types[i] << ", ";
        cout << types[types.size()-1] << "}";
    }
    if (p1 == "?") cout << " ";
    cout << (p2 == "?" ? "" : p2) << " " << child << "\n"; 
}

int main()
{
    //freopen("in.txt", "r", stdin);
    while (true)
    {
        cin >> p1 >> p2 >> child;
        if (p1 == "E")
            return 0;
        solve();
    }
}