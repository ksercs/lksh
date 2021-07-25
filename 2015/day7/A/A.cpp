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

char str1[2];
char str2[2];

int d1, d2;
int ch[12][12];
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2},
    dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

pair <int, int> prev[12][12];

pair <int, int> pl[2];
queue <pair <int, int> > q;
vector <pair <int, int> > ans;

void bfs()
{
 int i1, i2;
     while (!(q.empty()))
     {
         if (d1 != 0 && d2 != 0)
         {
           prev[i1][i2].first = d1;
           prev[i1][i2].second = d2;
          ]
           i1 = (q.front()).first; i2 = (q.front()).second;
           d1=i1; d2 = i2;
           if (i1 == pl[1].first && i2 == pl[1].second)
           {
                break;
           }
           for(int i=0; i<8; i++)
           {
                   if (ch[i1 + dx[i]][i2 + dy[i]] == 0)
                            {
                              ch[i1 + dx[i]][i2 + dy[i]] = 1;
                              q.push(make_pair(i1 + dx[i], i2 + dy[i]));
                              //cout << i1 + dx[i] <<" " <<i2 + dy[i] <<"\n";
                            }
           }
           q.pop();
     }
}

void in()
{
    ifstream cin("knight1.in");
    cin >>str1;
    cin >>str2;
}

void solution()
{
    int ind1, ind2;
    pl[0].first = str1[0] - 'a' + 2;
    pl[0].second = str1[1] - '0'+1;
    pl[1].first = str2[0] - 'a' + 2;
    pl[1].second = str2[1] - '0'+1;
    for (int i = 0; i <= 11; i++)
    {
        for (int j = 0; j <= 11; j++)
        {
            ch[i][j] = -1;
        }
    }
    for (int i = 2; i <= 9; i++)
    {
        for (int j = 2; j <= 9; j++)
        {
            ch[i][j] = 0;
        }
    }
    q.push(pl[0]);
    ch[2][2] = 1;
    bfs();
    ans.push_back(pl[1]);
    ind1 = pl[1].first; ind2 = pl[1].second;
    while (ind1 != pl[0].first && ind2 != pl[0].second)
    {
        cout <<ind1 << " " <<ind2 << "\n";
        cout <<prev[ind1][ind2].first << " " <<prev[ind1][ind2].second << "\n\n";
        ans.push_back(prev[ind1][ind2]);
        ind1 = prev[ind1][ind2].first;
        ind2 = prev[ind1][ind2].second;
    }
}

void out()
{
     ofstream cout("knight1.out");
     /*for (int i = ans.size()-1; i = 0; i--)
     {
         cout << ans[i].first << " " << ans[i].second << "\n";
     }*/
     cout << pl[0].first << " " <<pl[0].second << "\n";
     cout << pl[1].first << " " << pl[1].second <<"\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
