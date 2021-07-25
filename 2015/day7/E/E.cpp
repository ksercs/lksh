#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int board[10][10], used[10][10], ans[10][10];
int sum;
vector <pair <int, int> > way;

void f(int x, int y)
{
    way.push_back(make_pair(x, y);
    used[x][y] = 1;
    sum += board[x][y];
    if (board[x + 1][y + 1] <= board[x][y + 1] && board[x + 1][y + 1] <= board[x + 1][y] && used[x + 1][y + 1] == 0)
    {
        f(x + 1, y + 1);
    }
    else
    {
        if (board[x + 1][y] == board[x][y + 1])
        {

        }
    }
}

void in()
{
    ifstream cin("king2.in");
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            board[i][j] = -1;
        }
    }
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            cin >> board[i][j];
        }
    }
}

void solution()
{
    f(1, 1);
}

void out()
{
     ofstream cout("king2.out");
     cout << sum << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
