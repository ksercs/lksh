#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int n;
char table[13][13];
int used [13][13];
int dx[] = {1, -1, 0, 0},
    dy[] = {0, 0, 1, -1};

char col[] = {'R', 'G', 'B', 'Y', 'V'};
long long ans[5];

void f(int x, int y)
{
    n++;
    used[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        if (used[x + dx[i]][y + dy[i]] == 0 && table[x + dx[i]][y + dy[i]] == table[x][y])
        {
            f(x + dx[i], y + dy[i]);
        }
    }
}

void get_ans(int ind1, int ind2, long long cnt)
{
    for (int h = 0; h < 5; h ++)
    {
        if (table[ind1][ind2] == col[h])
        {
            ans[h] = max(ans[h], cnt*(cnt - 1));
        }
    }
}

void in()
{
    ifstream cin("balls.in");
    for (int i = 0; i <= 12; i++)
    {
        for (int j = 0; j <= 12; j++)
        {
            table[i][j] = -1;
        }
    }
    for (int i = 1; i <= 11; i++)
    {
        for (int j = 1; j <= 11; j++)
        {
            cin >> table[i][j];
        }
    }
}

void solution()
{
    for (int i = 1; i <= 11; i++)
    {
        for (int j = 1; j <= 11; j++)
        {
            if (used[i][j] == 0)
            {
                f(i, j);
                get_ans(i, j, n);
                n = 0;
            }
        }
    }
}

void out()
{
     ofstream cout("balls.out");
     for (int i = 0; i < 5; i++)
     {
         cout << col[i] << ": " << ans[i] << "\n";
     }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
