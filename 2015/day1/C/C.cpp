#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int n, res, pos;

//pair < pair < int, int >, int > pi;
pair <pair<int, int>, int> tmp;
pair <pair<int, int>, int> table[100000 + 2];

bool comp(pair <pair <int, int>, int> pi1, pair <pair <int, int>, int> pi2)
{
    if (pi1.first.first != pi2.first.first)
      return pi1.first.first < pi2.first.first;
    if (pi1.first.second != pi2.first.second)
      return pi1.first.second > pi2.first.second;
    return pi1.second > pi2.second;
}

void in()
{
    ifstream cin("ejudge.in");
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> res >> pos;
        // pi.first.first = res; pi.first.second = pos; pi.second = i;
        table[i] = make_pair(make_pair(res, pos), i);
    }
}

void solution()
{
    sort(table + 1, table + n + 1, comp);
}

void out()
{
     ofstream cout("ejudge.out");
     for (int i = n; i >= 1; i--)
     {
         cout << table[i].second << " ";
     }
     cout << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
