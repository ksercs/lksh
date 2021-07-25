#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstdio>


using namespace std;


const int MAX_SIZE = 60 + 2;

int n, m, st1, st2, fn1, fn2;

int mp[MAX_SIZE][MAX_SIZE], used[MAX_SIZE][MAX_SIZE];
int dx[] = {0, 0, 1, -1},
    dy[] = {1, -1, 0, 0};

void dfs(int a, int b)
{
     int ind;
     string s_q, s_a;
     string str[] = {"NORTH", "SOUTH", "EAST", "WEST"};
     used[a][b] = 1;
     cin >> s_q;
     if ()
     {

     }
     for (int i = 0; i < 4; i++)
     {
         if (s_q == str[i])
         {
             ind = i;
             break;
         }
     }
     if (used[a + dx[ind]][b + dy[ind]] == 0 && s_a == "EMPTY")
     {
         dfs(a + dx[ind], b + dy[ind]);
     }
}

int main()
{
    for (int i = 0; i <= 61; i++)
    {
        for (int j = 0; j <= 61; j++)
        {
            used[i][j] = 3;
        }
    }
    for (int i = 1; i <= 60; i++)
    {
        for (int j = 1; j <= 60; j++)
        {
            used[i][j] = 0;
        }
    }
    dfs(15, 15);
    cout << "DONE\n";
    return 0;
}
