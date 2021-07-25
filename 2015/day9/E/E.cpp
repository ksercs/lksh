#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAX_SIZE = 1000;

int n, m, st1, st2, fn1, fn2;

int mp[MAX_SIZE + 5][MAX_SIZE + 5], used[MAX_SIZE + 5][MAX_SIZE + 5], sum[MAX_SIZE + 5][MAX_SIZE + 5];
int dx[] = {0, 0, 1, -1},
    dy[] = {1, -1, 0, 0};

queue < pair <int, int> > q;
pair <int, int> pl;
pair <int, int> prev[MAX_SIZE + 5][MAX_SIZE + 5];

vector <pair <int, int> > way;

void bfs()
{
     while (!(q.empty()))
     {
         int i1, i2;
           i1 =(q.front()).first; i2 =(q.front()).second;
           used[i1][i2] = 1;
           for(int i = 0; i < 4; i++)
           {
                   if (mp[(q.front()).first + dx[i]][(q.front()).second + dy[i]] != -1 && used[(q.front()).first + dx[i]][(q.front()).second + dy[i]] == 0)
                   {
                        sum[i1+dx[i]][i2+dy[i]] = sum[i1][i2] + mp[i1+dx[i]][i2+dy[i]];
                        prev[i1+dx[i]][i2+dy[i]].first = i1;
                        prev[i1+dx[i]][i2+dy[i]].second = i2;
                        q.push(make_pair(i1+dx[i], i2+dy[i]));
                   }
           }
           q.pop();
     }
}

void in()
{
    ifstream cin("civ.in");
    char tmp[MAX_SIZE + 5][MAX_SIZE + 5];
    cin >> n >> m >> st1 >> st2 >> fn1 >> fn2;
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= m + 1; j++)
        {
            mp[i][j] = -1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> tmp[i][j];
            if (tmp[i][j] == '#')
            {
                mp[i][j] = -1;
            }
            if (tmp[i][j] == 'W')
            {
                mp[i][j] = 2;
            }
            if (tmp[i][j] == '.')
            {
                mp[i][j] = 1;
            }
        }
    }
}

void solution()
{
    q.push(make_pair(st1, st2));
    way.push_back(make_pair(st1, st2));
    bfs();
}

void out()
{
     ofstream cout("civ.out");
     int i1, i2;
     cout << sum[fn1][fn2] - 1 << "\n";
    /* i1 = fn1; i2 = fn2;
     way.push_back(make_pair(fn1, fn2));
     while (i1 != st1 && i2 != st2)
     {
        way.push_back(make_pair(prev[i1][i2].first, prev[i1][i2].second))
        ;
        i1 = prev[i1][i2].first;
        i2 = prev[i1][i2].second;
     }
     for (int i = way.size() - 1; i >= 0; i--)
     {
         cout << way[i].first << " " << way[i].second << "\n";
     }*/
     for (int i = 1; i <= n; i++)
     {
         for (int j = 1; j <= m; j++)
         {
            cout <<"<" << prev[i][j].first << " " << prev[i][j].second << "> ";
         }
         cout << "\n";
     }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
