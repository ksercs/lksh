#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

pair <int, int> king;
pair <int, int> rook[65];

int n, fl, fl_t;
int table[10][10];
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1},
    dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

char str[2];

void in()
{
    ifstream cin("rooks.in");
    cin >> str;
    king.first = str[0] - 'a' + 1;
    king.second = str[1] - '0';
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        rook[i].first = str[0] - 'a' + 1;
        rook[i].second = str[1] - '0';
    }
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
}

void solution()
{
    for (int i = 0; i < n; i++)
    {
        fl_t = table[rook[i].first][rook[i].second];
        for (int j = 1; j <= 8; j++)
        {
                table[rook[i].first][j] = 1;
                table[j][rook[i].second] = 1;
        }
        table[rook[i].first][rook[i].second] = fl_t;
        fl_t = 0;
    }
}

void out()
{
     ofstream cout("rooks.out");
     for (int i = 0; i < 8; i++)
     {
        if (table[king.first + dx[i]][king.second + dy[i]] == 0)
        {
            cout << char(king.first + dx[i] - 1  + 'a') << king.second + dy[i] << "\n";
            fl = 1;
            break;
        }
     }
     if (fl == 0)
     {
        if (table[king.first][king.second] == 0)
        {
            cout << "Stalemate\n";
        }
        else
        {
            cout << "Checkmate\n";
        }
     }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
