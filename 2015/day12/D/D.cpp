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
#include <cmath>

using namespace std;

const int POINT_COUNT = 100000;

double ans;
int n, x, y, fl;

pair <int, int> p[POINT_COUNT + 5];

bool cmp(pair <int, int> p1, pair <int, int> p2)
{

}

double f_corner(int i1, int i2)
{
    int cp, dp;
            pair <int, int> v1, v2;
            v1.first = x - p[i1].first;
            v1.second = y - p[i1].second;
            v2.first = x - p[i2].first;
            v2.second = y - p[i2].second;
            cp = v1.first * v2.second - v2.first * v1.second;
            dp = v1.first * v2.first + v1.second * v2.second;
            return abs(atan2(cp, dp)) / M_PI * 180;
}

void in()
{
    ifstream cin("point.in");
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;
    }
}

void solution()
{
    sort(p, p + n, cmp);
    for (int i = 0; i < n; i++)
    {
        cout << p[i].first << " " <<p[i].second << " " <<p[(i + 1) % n].first << " " << p[(i + 1) % n].second <<  "\n";
        ans += f_corner(i, (i + 1) % n);
        cout << ans << "\n";
    }
}

void out()
{
     ofstream cout("point.out");
     cout << ans << "\n";
     if (ans == 360)
     {
         cout << "YES\n";
     }
     else
     {
         cout << "NO\n";
     }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
