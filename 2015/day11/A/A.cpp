#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <queue>
#include <cmath>
#include <utility>
#include <vector>

using namespace std;

const int POINT_COUNT = 3;

pair <int, int> p[POINT_COUNT + 2];

double f_corner(int i1, int i2, int i3, double ans)
{
    double cp, dp;
    pair <int, int> v1, v2;
    v1.first = p[i2].first - p[i1].first;
    v1.second = p[i2].second - p[i1].second;
    v2.first = p[i3].first - p[i1].first;
    v2.second = p[i3].second - p[i1].second;
    cp = v1.first * v2.second - v2.first * v1.second;
    dp = v1.first * v2.first + v1.second * v2.second;
    return max(ans, abs(atan2(cp, dp)));
}

void in()
{
    //ifstream cin("goat1.in");
    for (int i = 0; i < POINT_COUNT; i++)
    {
        cin >> p[i].first >> p[i].second;
    }
}

void out()
{
    //ofstream cout("goat1.out");
    double answer = 0.0;
    cout.precision(10);
    for (int i = 0; i < POINT_COUNT; i++)
    {
        answer = f_corner(i, (i + 1) % POINT_COUNT, (i + 2) % POINT_COUNT, answer);
    }
    cout << answer / M_PI * 180 << "\n";
}

int main()
{
    in();
    out();
    return 0;
}
