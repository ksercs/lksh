#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstdio>


using namespace std;

int a, b, c, d;
double l_fun, mid_fun;

int bin_search(double l, double r)
{
    const int ITER = 1000;

    double mid;

    for (int i = 0; i < ITER; i++)
    {
        mid = (l + r) / 2;
        l_fun = a * l * l * l + b * l * l + c * l + d;
        mid_fun = a * mid * mid * mid + b * mid * mid + c * mid + d;
        if (l_fun * mid_fun <= 0)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout.precision(10);
    cout << l << "\n";
}

void in()
{
    ifstream cin("cubroot.in");
    cin >> a >> b >> c >> d;
}

void out()
{
     ofstream cout("cubroot.out");
     bin_search(-10000.0, 10000.0);
}

int main()
{
    in();
    out();
    return 0;
}
