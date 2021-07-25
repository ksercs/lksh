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

const int ANGLE_COUNT = 3;

int fl;

vector <pair <int, int> > tr;

double f_corner(int i1, int i2, int i3)
{
    double cp, dp;
    pair <int, int> v1, v2;
    v1.first = tr[i2].first - tr[i1].first;
    v1.second = tr[i2].second - tr[i1].second;
    v2.first = tr[i3].first - tr[i1].first;
    v2.second = tr[i3].second - tr[i1].second;
    cp = v1.first * v2.second - v2.first * v1.second;
    dp = v1.first * v2.first + v1.second * v2.second;
    return abs(atan2(cp, dp));
}

void in()
{
    ifstream cin("twotri.in");
    for (int i = 0; i < 2 * ANGLE_COUNT; i++)
    {
        int a, b, c, d, e, g;
        cin >> a >> b >> c >> d >> e >> g ;
        tr.push_back(make_pair(a, b));
        tr.push_back(make_pair(c, d));
        tr.push_back(make_pair(e, g));
    }
}

void solution()
{
    for (int i = 0; i < ANGLE_COUNT; i++)
    {
         cout << f_corner(i, (i + 1) % ANGLE_COUNT, (i + 2) % ANGLE_COUNT) << " " << f_corner(i + ANGLE_COUNT, (i + ANGLE_COUNT + 1) % (2 * ANGLE_COUNT), (i + ANGLE_COUNT + 2) % (2 * ANGLE_COUNT)) << "\n";
        if (f_corner(i, (i + 1) % ANGLE_COUNT, (i + 2) % ANGLE_COUNT) == f_corner(i + ANGLE_COUNT, (i + ANGLE_COUNT + 1) % (2 * ANGLE_COUNT), (i + ANGLE_COUNT + 2) % (2 * ANGLE_COUNT)))
        {
            fl++;
        }
    }
}

void out()
{
     ofstream cout("twotri.out");
     if (fl == ANGLE_COUNT)
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
