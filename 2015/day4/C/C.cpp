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

const int MAX_COUNT = 100000;

int n, m, point;

vector <pair <int, int> > events(MAX_COUNT + 5);

int ans[MAX_COUNT + 5];

bool cmp(pair <int, int> pi1, pair <int, int> pi2)
{
    if (pi1.first != pi2.first)
    {
        return pi1.first < pi2.first;
    }
    else
    {
        return pi1.second > pi2.second;
    }
}

void in()
{
    ifstream cin("segments.in");
    cin >> n >> m;
    int l, r;
    for (int i = 0; i <  n; i++)
    {
        cin >> l >> r;
        events[2 * i] = (make_pair(min(l, r), 1));
        events[2 * i + 1] = (make_pair(max(l, r), -1));
    }
    for (int i = n; i < 2 * n + m; i++)
    {
        cin >> point;
        events[i] = make_pair(point, i);
    }
}

void solution()
{
    //sort(events.begin(), events.end(), cmp);
    for (int i = 0; i < 2 * n + m; i++)
    {
        cout << events[i].first << " " << events[i].second << "\n";
    }
    int bal;
    for (int i = 0; i < 2 * n; i++)
    {
        if (events[i].second == 1 || events[i].second == -1)
        {
            bal += events[i].second;
        }
        else
        {
            ans[events[i].second] = bal;
        }
    }
}

void out()
{
     ofstream cout("segments.out");
     for (int i = 2 * n; i < 2 * n + m; i++)
     {
         cout << ans[i] <<" ";
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
