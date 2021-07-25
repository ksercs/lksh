#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int table[30][30];
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2},
    dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

vector <pair <char, int> > ans;

void f(int x, int y, int st1, int st2)
{
    for(int i = 0; i < 8; i++)
    {
        if (table[st1 + dx[i]][st2 + dy[i]] == 0)
        {
            ans.push_back(make_pair(st1 + dx[i] - 1 + 'a' - 1, st2 + dy[i] - 1));
            table[st1 + dx[i]][st2 + dy[i]] = 1;
            f(x, y, st1 + dx[i], st2 + dy[i]);
        }
    }
}

int main()
{
    ofstream cout("F.out");
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n + 3; i++)
    {
        for (int j = 0; j <= m + 3; j++)
        {
            table[i][j] = -1;
        }
    }
    for (int i = 2; i <= n + 1; i++)
    {
        for (int j = 2; j <= m + 1; j++)
        {
            table[i][j] = 0;
        }
    }
    //cout <<int('_') << " "; cout << int(',') <<"\n";
    table[2][2] = 1;
    ans.push_back(make_pair('a', 1));
    f(n, m, 2, 2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << ans[i].second << "\n";
    }
    return 0;
}
