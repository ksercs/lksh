#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAX_COUNT = 10000, MAX_LENGTH = 10000000;

long long sum;
int n, k;
int length[MAX_COUNT + 2];

int bin_search(int l, int r)
{
    int mid, cnt;
    while (r - l > 1)
    {
        //cout <<l <<" " <<r <<"\n";
        mid = (r+l) / 2;
        cnt = 0;
        for (int i = 1; i <= n; i++)
        {
           cnt += length[i] / mid;
        }
        if (cnt >= k)
        {
           l = mid;
        }
        else
        {
           r = mid;
        }
    }
    return l;
}

void in()
{
    ifstream cin("ropes.in");
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
       cin >> length[i];
    }
}

void out()
{
     ofstream cout("ropes.out");
     cout << bin_search(0, MAX_LENGTH+2) << "\n";
}

int main()
{
    in();
    out();
    return 0;
}
