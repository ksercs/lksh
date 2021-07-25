#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int t, k, fl;

pair <int, int> st, fn;

pair <int, int> tel[100], hor[100];
queue <pair <int, int> > q;

int table[15][15];
int dxh[] = {-2, -2, -1, -1, 1, 1, 2, 2},
    dyh[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dxk[] = {0, 0, 1, -1, 1, 1, -1, -1},
    dyk[] = {1, -1, 0, 0, 1, -1, 1, -1};

void bfs()
{
     int i1, i2;
     while (!(q.empty()))
     {
           i1 = (q.front()).first; i2 = (q.front()).second;
           table[i1][i2] = 1;
           if (i1 == fn.first && i2 == fn.second)
           {
                fl = 1;
           }
           for (int i = 0; i < 8; i++)
           {
                   if (table[i1 + dxk[i]][i2 + dyk[i]] == 0)
                            {
                              q.push(make_pair(i1 + dxk[i], i2 + dyk[i]));
                            }
           }
           q.pop();
     }
}

void in()
{
    ifstream cin("stone.in");
    char str[5];
    cin >> str;
    st.first = str[0] - 'a' + 1;
    st.second = str[1] - '0';
    cin >> str;
    fn.first = str[0] - 'a' + 1;
    fn.second = str[1] - '0';
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> str;
        tel[i].first = str[0] - 'a' + 1;
        tel[i].second = str[1] - '0';
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> str;
        hor[i].first = str[0] - 'a' + 1;
        hor[i].second = str[1] - '0';
    }
}

void solution()
{
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
           table[i][j] = -1;
        }
    }
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
           table[i][j] = 0;
        }
    }
    for (int i = 0; i < t; i++)
    {
        table[tel[i].first][tel[i].second] = -1;
    }
    for (int i = 0; i < k; i++)
    {
        table[hor[i].first][hor[i].second] = -1;
        for (int j = 0; j < 8; j++)
        {
            table[hor[i].first + dxh[j]][hor[i].second + dyh[j]] = -1;
        }
    }
    q.push(st);
    bfs();
}

void out()
{
     ofstream cout("stone.out");
     if (fl == 1)
     {
         cout << "YES\n";
     }
     else
     {
         cout << "NO\n";
     }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
