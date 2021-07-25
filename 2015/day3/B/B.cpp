#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int  INF = 1000000;

int n, bal, st = -1 * INF, fn = -1 * INF, start, finish;

vector <pair <int, int> > ans;
vector <pair <int, int> > events;

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
    ifstream cin("merge.in");
    cin >> n;
    for (int i = 0; i < 2 * n; i+=2)
    {
        cin >> start >> finish;
        events.push_back(make_pair(min(start, finish), 1));
        events.push_back(make_pair(max(start, finish), -1));
    }
}

void solution()
{
  sort(events.begin(), events.end(), cmp);
  for (int i = 0; i < 2 * n; i++)
  {
        if (bal == 0 && bal + events[i].second == 1)
        {
            st = events[i].first;
        }
        if (bal == 1 && bal + events[i].second == 0)
        {
            fn = events[i].first;
        }
        bal += events[i].second;
        if (st != -1000000 && fn != -1000000)
        {
            ans.push_back(make_pair(st, fn));
            st = -1000000;
            fn = -1000000;
        }
  }
}

void out()
{
    ofstream cout("merge.out");
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
