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

const double EPS = 1e-7;

int v_p, v_f;
double a;

double find_v(double s)
{
    return sqrt((1 - a) * (1 - a) + s * s) / v_p + sqrt(a * a + (1 - s) * (1 - s)) / v_f;
}

double t_search(double l, double r)
{
    while (r - l > EPS)
    {
        double l_p, r_p;
        l_p = l + (r - l) / 3;
        r_p = l + (r - l) / 3 * 2;
        if (find_v(l_p) < find_v(r_p))
        {
            r = r_p;
        }
        else
        {
            l = l_p;
        }
    }
    return l;
}

void in()
{
    ifstream cin("forest.in");
    cin >> v_p >> v_f;
    cin >> a;
}

void out()
{
     ofstream cout("forest.out");
     cout.precision(10);
     cout << t_search(0.0, 1.0) << "\n";
}

int main()
{
    in();
    out();
    return 0;
}
