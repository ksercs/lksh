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

const int MAX_COUNT = 50000 + 5;

int n;

pair <int, int> ztime[MAX_COUNT];

vector <int> ans;

void in()
{
    ifstream cin("timetable.in");
    cin >> n;
    for (int i = 0; i < 2 * n; i++)
    {
        int a, b;
        cin >> a >> b;
        ztime[i] = make_pair(a, b);
    }
}

void solution()
{
    sort(ztime, ztime + n);
    for (int g = 0; g < n - 1; g++)
    {
        int ind = g;
        q[wq[e]
    for (int h = g + 1; h < n; h++)
    {
        if (ztime[g].first.second <= ztime[h].first.first)
        {
            ans.push_back(ztime[i].second);
            g = h; h++;
        }
    }
    }
}

void out()
{
     ofstream cout("timetable.out");
     for (int i = 0; i < ans.size(); i++)
     {
         cout << ans[i] + 1 << " ";
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
