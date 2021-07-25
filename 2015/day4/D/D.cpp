#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

pair <pair <int, int>, pair <int, int> > rect[1500 + 2];

void in()
{
    ifstream cin("union.in");
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
     cin >> rect[i].first.first >> rect[i].first.second >> rect[i].second.first >> rect[i].second.second;
    }
}

void solution()
{
    sort(rect+1, rect+n+1);

    for (int i = 2; i <= n; i++)
    {
       if (rect[i - 1].second.first - rect[i].first.first >= 0 && rect[i - 1].second.second - rect[i - 1].first.second >= 0)
       {
         rect[i].first.first = rect[i].first.first;
         rect[i].first.second = rect[i].first.second;
         rect[i].second.first = rect[i - 1].second.first;
         rect[i].second.second = rect[i - 1].second.second;
       }
       else
       {
         fl = 1; break;
       }
    }
}

void out()
{
     ofstream cout("union.out");
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
